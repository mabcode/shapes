#include <catch2/catch.hpp>

#include "../Triangle.cpp"
#include <fstream>

TEST_CASE("Checking the methods in the Triangle class", "[triangle]")
{
    SECTION("Checking the constructor")
    {
        Triangle *tri = new Triangle(6, 0, 12, 0, 9, 9);
        CHECK(tri->getx1() == 6);
        CHECK(tri->gety1() == 0);
        CHECK(tri->getx2() == 12);
        CHECK(tri->gety2() == 0);
        CHECK(tri->getx3() == 9);
        CHECK(tri->gety3() == 9);
        delete tri;
    }
    SECTION("Checking the move()")
    {
        Triangle *tri = new Triangle(6, 0, 12, 0, 9, 9);
        tri->move(10, 10);
        CHECK(tri->getx1() == 16);
        CHECK(tri->gety1() == 10);
        CHECK(tri->getx2() == 22);
        CHECK(tri->gety2() == 10);
        CHECK(tri->getx3() == 19);
        CHECK(tri->gety3() == 19);
        delete tri;
    }
    SECTION("Checking the scale()")
    {
        int x1 = 6;
        int y1 = 0;
        int x2 = 12;
        int y2 = 0;
        int x3 = 9;
        int y3 = 9;
        int scaleBy = 2;

        Triangle *tri = new Triangle(x1, y1, x2, y2, x3, y3);
        tri->scale(scaleBy);

        double centerX = (x1 + x2 + x3) / 3;
        double centerY = (y1 + y2 + y3) / 3;

        CHECK(tri->getx1() == (scaleBy * x1 - centerX));
        CHECK(tri->gety1() == (scaleBy * y1 - centerY));
        CHECK(tri->getx2() == (scaleBy * x2 - centerX));
        CHECK(tri->gety2() == (scaleBy * y2 - centerY));
        CHECK(tri->getx3() == (scaleBy * x3 - centerX));
        CHECK(tri->gety3() == (scaleBy * y3 - centerY));
        delete tri;
    }
    SECTION("Checking the area()")
    {
        int x1 = 6;
        int y1 = 0;
        int x2 = 12;
        int y2 = 0;
        int x3 = 9;
        int y3 = 9;

        Triangle *tri = new Triangle(x1, y1, x2, y2, x3, y3);
        double tempArea = -1;
        tempArea = tri->area();

        double tempHeight = y3 - y1;

        CHECK(tri->getx1() == 6);
        CHECK(tri->gety1() == 0);
        CHECK(tri->getx2() == 12);
        CHECK(tri->gety2() == 0);
        CHECK(tri->getx3() == 9);
        CHECK(tri->gety3() == 9);
        CHECK(tempArea == (((x2 - x1) * tempHeight) / 2));
        delete tri;
    }

    SECTION("Checking the fileOut() and fileIn()")
    {
        std::string tempClass;
        Triangle *tri = new Triangle(6, 0, 12, 0, 9, 9);
        Triangle *tri3 = new Triangle(16, 10, 22, 10, 19, 19);
        std::ofstream out;
        out.open("testPoint.txt");
        tri->fileOut(out);
        tri3->fileOut(out);

        Triangle *tri2 = new Triangle(-1, -2, -3, -4, -5, -6);
        Triangle *tri4 = new Triangle(-7, -8, -9, -10, -11, -12);

        CHECK(tri2->getx1() == -1);
        CHECK(tri2->gety1() == -2);
        CHECK(tri2->getx2() == -3);
        CHECK(tri2->gety2() == -4);
        CHECK(tri2->getx3() == -5);
        CHECK(tri2->gety3() == -6);

        CHECK(tri4->getx1() == -7);
        CHECK(tri4->gety1() == -8);
        CHECK(tri4->getx2() == -9);
        CHECK(tri4->gety2() == -10);
        CHECK(tri4->getx3() == -11);
        CHECK(tri4->gety3() == -12);

        std::ifstream in;
        in.open("testPoint.txt");
        in >> tempClass;
        CHECK(tempClass == "Triangle");
        tri2->fileIn(in);
        in >> tempClass;
        CHECK(tempClass == "Triangle");
        tri4->fileIn(in);

        CHECK(tri2->getx1() == 6);
        CHECK(tri2->gety1() == 0);
        CHECK(tri2->getx2() == 12);
        CHECK(tri2->gety2() == 0);
        CHECK(tri2->getx3() == 9);
        CHECK(tri2->gety3() == 9);

        CHECK(tri4->getx1() == 16);
        CHECK(tri4->gety1() == 10);
        CHECK(tri4->getx2() == 22);
        CHECK(tri4->gety2() == 10);
        CHECK(tri4->getx3() == 19);
        CHECK(tri4->gety3() == 19);

        CHECK(tri->getx1() == tri2->getx1());
        CHECK(tri->gety1() == tri2->gety1());
        CHECK(tri->getx2() == tri2->getx2());
        CHECK(tri->gety2() == tri2->gety2());
        CHECK(tri->getx3() == tri2->getx3());
        CHECK(tri->gety3() == tri2->gety3());

        CHECK(tri3->getx1() == tri4->getx1());
        CHECK(tri3->gety1() == tri4->gety1());
        CHECK(tri3->getx2() == tri4->getx2());
        CHECK(tri3->gety2() == tri4->gety2());
        CHECK(tri3->getx3() == tri4->getx3());
        CHECK(tri3->gety3() == tri4->gety3());

        delete tri;
        delete tri2;
        delete tri3;
        delete tri4;
    }
}