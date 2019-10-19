#include <catch2/catch.hpp>

#include "../ShapeGroup.cpp"
#include "../Image.cpp"
#include "../Point.cpp"
#include <fstream>

TEST_CASE("Checking the methods in the point class", "[point]")
{
    SECTION("Checking the constructor")
    {
        Point *point = new Point(5, 9);
        REQUIRE(point->getx() == 5);
        REQUIRE(point->gety() == 9);
        delete point;
    }
    SECTION("Checking the move()")
    {
        Point *point = new Point(5, 9);
        point->move(10, 10);
        REQUIRE(point->getx() == 15);
        REQUIRE(point->gety() == 19);
        delete point;
    }
    SECTION("Checking the scale()")
    {
        Point *point = new Point(2, 2);
        point->scale(10);
        REQUIRE(point->getx() == 2);
        REQUIRE(point->gety() == 2);
        delete point;
    }
    SECTION("Checking the area()")
    {
        Point *point = new Point(2, 2);
        double tempArea = -1;
        tempArea = point->area();
        REQUIRE(point->getx() == 2);
        REQUIRE(point->gety() == 2);
        REQUIRE(tempArea == 0);

        delete point;
    }
    SECTION("Checking the fileOut() and fileIn()")
    {
        std::string tempClass;
        Point *point = new Point(2, 3);
        Point *point3 = new Point(5, 5);
        std::ofstream out;
        out.open("testPoint.txt");
        point->fileOut(out);
        point3->fileOut(out);

        Point *point2 = new Point(0, 0);
        Point *point4 = new Point(0, 0);

        CHECK(point2->getx() == 0);
        CHECK(point2->gety() == 0);
        CHECK(point4->getx() == 0);
        CHECK(point4->gety() == 0);

        std::ifstream in;
        in.open("testPoint.txt");
        in >> tempClass;
        CHECK(tempClass == "Point");
        point2->fileIn(in);
        in >> tempClass;
        CHECK(tempClass == "Point");
        point4->fileIn(in);

        CHECK(point2->getx() == 2);
        CHECK(point2->gety() == 3);
        CHECK(point4->getx() == 5);
        CHECK(point4->gety() == 5);

        delete point;
        delete point2;
        delete point3;
        delete point4;
    }
}