#include <catch2/catch.hpp>

#include "../Circle.cpp"
#include <fstream>

TEST_CASE("Checking the methods in the circle class", "[circle]")
{
    SECTION("Checking the constructor")
    {
        Circle *cir = new Circle(3, 5, 33);
        CHECK(cir->getx() == 3);
        CHECK(cir->gety() == 5);
        CHECK(cir->getRad() == 33);
        delete cir;
    }
    SECTION("Checking the move()")
    {
        Circle *cir = new Circle(3, 5, 33);
        cir->move(10, 10);
        CHECK(cir->getx() == 13);
        CHECK(cir->gety() == 15);
        CHECK(cir->getRad() == 33);
        delete cir;
    }
    SECTION("Checking the scale()")
    {
        Circle *cir = new Circle(3, 5, 10);
        cir->scale(10);
        CHECK(cir->getx() == 3);
        CHECK(cir->gety() == 5);
        CHECK(cir->getRad() == 100);
        delete cir;
    }
    SECTION("Checking the area()")
    {
        Circle *cir = new Circle(3, 5, 10);
        double tempArea = -1;
        tempArea = cir->area();
        CHECK(cir->getx() == 3);
        CHECK(cir->gety() == 5);
        CHECK(cir->getRad() == 10);
        CHECK(tempArea == (3.14159265359 * (10 * 10)));
        delete cir;
    }
    SECTION("Checking the fileOut() and fileIn()")
    {
        std::string tempClass;
        Circle *cir = new Circle(2, 3, 10);
        Circle *cir3 = new Circle(5, 5, 100);
        std::ofstream out;
        out.open("testPoint.txt");
        cir->fileOut(out);
        cir3->fileOut(out);

        Circle *cir2 = new Circle(-1, -2, -3);
        Circle *cir4 = new Circle(-4, -5, -6);

        CHECK(cir2->getx() == -1);
        CHECK(cir2->gety() == -2);
        CHECK(cir2->getRad() == -3);
        CHECK(cir4->getx() == -4);
        CHECK(cir4->gety() == -5);
        CHECK(cir4->getRad() == -6);

        std::ifstream in;
        in.open("testPoint.txt");
        in >> tempClass;
        CHECK(tempClass == "Circle");
        cir2->fileIn(in);
        in >> tempClass;
        CHECK(tempClass == "Circle");
        cir4->fileIn(in);

        CHECK(cir2->getx() == 2);
        CHECK(cir2->gety() == 3);
        CHECK(cir2->getRad() == 10);
        CHECK(cir4->getx() == 5);
        CHECK(cir4->gety() == 5);
        CHECK(cir4->getRad() == 100);

        CHECK(cir->getx() == cir2->getx());
        CHECK(cir->gety() == cir2->gety());
        CHECK(cir->getRad() == cir2->getRad());
        CHECK(cir3->getx() == cir4->getx());
        CHECK(cir3->gety() == cir4->gety());
        CHECK(cir3->getRad() == cir4->getRad());

        delete cir;
        delete cir2;
        delete cir3;
        delete cir4;
    }
}