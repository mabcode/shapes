#include <catch2/catch.hpp>

#include "../Circle.cpp"
#include <fstream>

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
    SECTION("Checking the move()")
    {
        Circle *cir = new Circle(3,5,33);
        cir->move(10,10);
        CHECK(cir->getx() == 13);
        CHECK(cir->gety() == 15);
        CHECK(cir->getRad() == 33);
        delete cir;
    }
    SECTION("Checking the scale()")
    {
        Circle *cir = new Circle(3,5,10);
        cir->scale(10);
        CHECK(cir->getx() == 3);
        CHECK(cir->gety() == 5);
        CHECK(cir->getRad() == 100);
        delete cir;
    }
    SECTION("Checking the area()")
    {
        Circle *cir = new Circle(3,5,10);
        double tempArea = -1;
        tempArea = cir->area();
        CHECK(cir->getx() == 3);
        CHECK(cir->gety() == 5);
        CHECK(cir->getRad() == 10);
        CHECK(tempArea == (3.14159265359*(10*10)));
        delete cir;
    }
}