#include <catch2/catch.hpp>

#include "../Rectangle.cpp"
#include <fstream>

TEST_CASE("Checking the methods in the Rectangle class", "[rectangle]")
{
    SECTION("Checking the constructor")
    {
        Rectangle *rec = new Rectangle(5, 0, 12, 0, 10);
        CHECK(rec->getx1() == 5);
        CHECK(rec->gety1() == 0);
        CHECK(rec->getx2() == 12);
        CHECK(rec->gety2() == 0);
        CHECK(rec->getHeight() == 10);
        delete rec;
    }
    SECTION("Checking the move()")
    {
        Rectangle *rec = new Rectangle(5, 0, 12, 0, 10);
        rec->move(100, 100);
        CHECK(rec->getx1() == 105);
        CHECK(rec->gety1() == 100);
        CHECK(rec->getx2() == 112);
        CHECK(rec->gety2() == 100);
        CHECK(rec->getHeight() == 10);
        delete rec;
    }
    SECTION("Checking the scale()")
    {
        Rectangle *rec = new Rectangle(5, 0, 12, 0, 10);
        rec->scale(2);
        CHECK(rec->getx1() == 5);
        CHECK(rec->gety1() == 0);
        CHECK(rec->getx2() == 24);
        CHECK(rec->gety2() == 0);
        CHECK(rec->getHeight() == 20);
        delete rec;
    }
    SECTION("Checking the area()")
    {
        Rectangle *rec = new Rectangle(5, 0, 12, 0, 10);
        double tempArea = -1;
        tempArea = rec->area();
        CHECK(rec->getx1() == 5);
        CHECK(rec->gety1() == 0);
        CHECK(rec->getx2() == 12);
        CHECK(rec->gety2() == 0);
        CHECK(rec->getHeight() == 10);
        CHECK(tempArea == (12-5)*10);
        delete rec;
    }

    SECTION("Checking the fileOut() and fileIn()")
    {
        std::string tempClass;
        Rectangle *rec = new Rectangle(2, 2, 4, 4, 10);
        Rectangle *rec3 = new Rectangle(6, 6, 8, 8, 10);
        std::ofstream out;
        out.open("testPoint.txt");
        rec->writeToFile(out);
        rec3->writeToFile(out);

        Rectangle *rec2 = new Rectangle(-1, -2, -3, -4, -99);
        Rectangle *rec4 = new Rectangle(-5, -6, -7, -8, -88);

        CHECK(rec2->getx1() == -1);
        CHECK(rec2->gety1() == -2);
        CHECK(rec2->getx2() == -3);
        CHECK(rec2->gety2() == -4);
        CHECK(rec2->getHeight() == -99);

        CHECK(rec4->getx1() == -5);
        CHECK(rec4->gety1() == -6);
        CHECK(rec4->getx2() == -7);
        CHECK(rec4->gety2() == -8);
        CHECK(rec4->getHeight() == -88);

        std::ifstream in;
        in.open("testPoint.txt");
        in >> tempClass;
        CHECK(tempClass == "Rectangle");
        rec2->readFromFile(in);
        in >> tempClass;
        CHECK(tempClass == "Rectangle");
        rec4->readFromFile(in);

        CHECK(rec2->getx1() == 2);
        CHECK(rec2->gety1() == 2);
        CHECK(rec2->getx2() == 4);
        CHECK(rec2->gety2() == 4);
        CHECK(rec2->getHeight() == 10);

        CHECK(rec4->getx1() == 6);
        CHECK(rec4->gety1() == 6);
        CHECK(rec4->getx2() == 8);
        CHECK(rec4->gety2() == 8);
        CHECK(rec4->getHeight() == 10);

        CHECK(rec->getx1() == rec2->getx1());
        CHECK(rec->gety1() == rec2->gety1());
        CHECK(rec->getx2() == rec2->getx2());
        CHECK(rec->gety2() == rec2->gety2());
        CHECK(rec->getHeight() == rec2->getHeight());
        
        CHECK(rec3->getx1() == rec4->getx1());
        CHECK(rec3->gety1() == rec4->gety1());
        CHECK(rec3->getx2() == rec4->getx2());
        CHECK(rec3->gety2() == rec4->gety2());
        CHECK(rec3->getHeight() == rec4->getHeight());

        delete rec;
        delete rec2;
        delete rec3;
        delete rec4;
    }
}