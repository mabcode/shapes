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
    
}