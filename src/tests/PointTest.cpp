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
    SECTION("Checking the scale()")
    {
        Point *point = new Point(2,2);
        point->scale(10);
        REQUIRE(point->getx() == 2);
        REQUIRE(point->gety() == 2);
        delete point;
    }
    SECTION("Checking the area()")
    {
        Point *point = new Point(2,2);
        double tempArea = -1;
        tempArea = point->area();
        REQUIRE(point->getx() == 2);
        REQUIRE(point->gety() == 2);
        REQUIRE(tempArea == 0);

        delete point;
    }
    
}