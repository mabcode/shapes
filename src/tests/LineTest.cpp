#include <catch2/catch.hpp>

#include "../Line.cpp"
#include <fstream>

TEST_CASE("Checking the methods in the Line class", "[line]")
{
    SECTION("Checking the constructor")
    {
        Line *line = new Line(5, 9, 12, 51);
        CHECK(line->getx1() == 5);
        CHECK(line->gety1() == 9);
        CHECK(line->getx2() == 12);
        CHECK(line->gety2() == 51);
        delete line;
    }
    SECTION("Checking the move()")
    {
        Line *line = new Line(5, 9, 12, 51);
        line->move(100, 100);
        CHECK(line->getx1() == 105);
        CHECK(line->gety1() == 109);
        CHECK(line->getx2() == 112);
        CHECK(line->gety2() == 151);
        delete line;
    }
    SECTION("Checking the scale()")
    {
        Line *line = new Line(5, 9, 50, 60);
        line->scale(2);
        CHECK(line->getx1() == 5);
        CHECK(line->gety1() == 9);
        CHECK(line->getx2() == 100);
        CHECK(line->gety2() == 60);
        delete line;
    }
    SECTION("Checking the area()")
    {
        Line *line = new Line(5, 9, 50, 60);
        double tempArea = -1;
        tempArea = line->area();
        CHECK(line->getx1() == 5);
        CHECK(line->gety1() == 9);
        CHECK(line->getx2() == 50);
        CHECK(line->gety2() == 60);
        CHECK(tempArea == 0);
        delete line;
    }

    SECTION("Checking the fileOut() and fileIn()")
    {
        std::string tempClass;
        Line *line = new Line(2, 2, 4, 4);
        Line *line3 = new Line(6, 6, 8, 8);
        std::ofstream out;
        out.open("testPoint.txt");
        line->writeToFile(out);
        line3->writeToFile(out);

        Line *line2 = new Line(-1, -2, -3, -4);
        Line *line4 = new Line(-5, -6, -7, -8);

        CHECK(line2->getx1() == -1);
        CHECK(line2->gety1() == -2);
        CHECK(line2->getx2() == -3);
        CHECK(line2->gety2() == -4);

        CHECK(line4->getx1() == -5);
        CHECK(line4->gety1() == -6);
        CHECK(line4->getx2() == -7);
        CHECK(line4->gety2() == -8);

        std::ifstream in;
        in.open("testPoint.txt");
        in >> tempClass;
        CHECK(tempClass == "Line");
        line2->readFromFile(in);
        in >> tempClass;
        CHECK(tempClass == "Line");
        line4->readFromFile(in);

        CHECK(line2->getx1() == 2);
        CHECK(line2->gety1() == 2);
        CHECK(line2->getx2() == 4);
        CHECK(line2->gety2() == 4);

        CHECK(line4->getx1() == 6);
        CHECK(line4->gety1() == 6);
        CHECK(line4->getx2() == 8);
        CHECK(line4->gety2() == 8);

        CHECK(line->getx1() == line2->getx1());
        CHECK(line->gety1() == line2->gety1());
        CHECK(line->getx2() == line2->getx2());
        CHECK(line->gety2() == line2->gety2());

        CHECK(line3->getx1() == line4->getx1());
        CHECK(line3->gety1() == line4->gety1());
        CHECK(line3->getx2() == line4->getx2());
        CHECK(line3->gety2() == line4->gety2());


        delete line;
        delete line2;
        delete line3;
        delete line4;
    }
    SECTION("Checking the draw()")
    {
        Line *line = new Line(50, 10, 200, 200);
        line->draw();
        delete line;
    }
}