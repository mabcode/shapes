#include <catch2/catch.hpp>

#include "../Line.cpp"

TEST_CASE("Checking the methods in the Line class", "[line]")
{
    SECTION("Checking the constructor")
    {
        Line *line = new Line(5,9,12,51);
        CHECK(line->getx1() == 5);
        CHECK(line->gety1() == 9);
        CHECK(line->getx2() == 12);
        CHECK(line->gety2() == 51);
        delete line;
    }
    SECTION("Checking the move()")
    {
        Line *line = new Line(5,9,12,51);
        line->move(100,100);
        CHECK(line->getx1() == 105);
        CHECK(line->gety1() == 109);
        CHECK(line->getx2() == 112);
        CHECK(line->gety2() == 151);
        delete line;
    }
    SECTION("Checking the scale()")
    {
        Line *line = new Line(5,9,50,60);
        line->scale(2);
        CHECK(line->getx1() == 5);
        CHECK(line->gety1() == 9);
        CHECK(line->getx2() == 100);
        CHECK(line->gety2() == 60);
        delete line;
    }
    
}