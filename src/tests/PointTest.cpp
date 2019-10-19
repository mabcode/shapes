#include <catch2/catch.hpp>

#include "../ShapeGroup.cpp"
#include "../Image.cpp"
#include "../Point.cpp"

TEST_CASE("Checking the methods in the point class", "[point]")
{
    SECTION("Checking the constructor")
    {
        Point *point = new Point(5,9);
        REQUIRE(point->getx() == 5);
        REQUIRE(point->gety() == 9);
        delete point;
    }
    SECTION("Checking the move()")
    {
        Point *point = new Point(5,9);
        point->move(10,10);
        REQUIRE(point->getx() == 15);
        REQUIRE(point->gety() == 19);
        delete point;
    }
    
}