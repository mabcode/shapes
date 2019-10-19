#include <catch2/catch.hpp>

#include "../Circle.cpp"

TEST_CASE("Checking the methods in the circle class", "[circle]")
{
    SECTION("Checking the constructor")
    {
        Circle *cir = new Circle(3,5,33);
        CHECK(cir->getx() == 3);
        CHECK(cir->gety() == 5);
        CHECK(cir->getRad() == 33);
        delete cir;
    }
}