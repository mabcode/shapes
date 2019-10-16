#include <catch2/catch.hpp>

#include "../ShapeGroup.cpp"
#include "../Image.cpp"
#include "../Point.cpp"
#include "../Line.cpp"
#include "../Circle.cpp"

TEST_CASE("Checking that you can have a group of point", "[composite]")
{
    SECTION("Checking groups of points")
    {
        Image *pointGroup1 = new ShapeGroup("point group 1");
        Image *pointGroup2 = new ShapeGroup("point group 2");

        Image *allPointGroups = new ShapeGroup("Points");

        allPointGroups->add(pointGroup1);
        pointGroup1->add(new Point(1, 2));
        pointGroup1->add(new Point(1, 2));
        pointGroup1->add(new Point(3, 3));

        allPointGroups->add(pointGroup2);
        pointGroup2->add(new Point(3, 3));
        pointGroup2->add(new Point(4, 3));
        pointGroup2->add(new Point(5, 3));

        allPointGroups->draw();
        allPointGroups->move(10,10);
        std::cout << std::endl;
        std::cout << "POINTS AFTER BEING MOVED \n";
        allPointGroups->draw();
        std::cout << std::endl;
    }

    SECTION("Checking groups of points and lines")
    {
        Image *pointGroup1 = new ShapeGroup("point and Line group 1");
        Image *pointGroup2 = new ShapeGroup("point and Line group 2");

        Image *allPointGroups = new ShapeGroup("Points and lines");

        allPointGroups->add(pointGroup1);
        pointGroup1->add(new Point(1, 2));
        pointGroup1->add(new Point(1, 2));
        pointGroup1->add(new Point(3, 3));
        pointGroup1->add(new Line(6, 6, 12, 12));
        pointGroup1->add(new Line(0, 1, 23, 44));

        allPointGroups->add(pointGroup2);
        pointGroup2->add(new Point(3, 3));
        pointGroup2->add(new Point(4, 3));
        pointGroup2->add(new Point(5, 3));
        pointGroup2->add(new Line(1, 1, 2, 2));
        pointGroup2->add(new Line(2, 2, 3, 3));

        allPointGroups->draw();
        std::cout << std::endl;
    }

    SECTION("Checking groups of points and lines")
    {
        Image *pointGroup1 = new ShapeGroup("point, Line, and Circles group 1");
        Image *pointGroup2 = new ShapeGroup("point, Line, and Circles group 2");

        Image *allPointGroups = new ShapeGroup("Points, Line, and Circles");

        allPointGroups->add(pointGroup1);
        pointGroup1->add(new Point(1, 2));
        pointGroup1->add(new Point(1, 2));
        pointGroup1->add(new Point(3, 3));
        pointGroup1->add(new Line(6, 6, 12, 12));
        pointGroup1->add(new Line(0, 1, 23, 44));
        pointGroup1->add(new Circle(6, 6, 12));
        pointGroup1->add(new Circle(0, 1, 23));

        allPointGroups->add(pointGroup2);
        pointGroup2->add(new Point(3, 3));
        pointGroup2->add(new Point(4, 3));
        pointGroup2->add(new Point(5, 3));
        pointGroup2->add(new Line(1, 1, 2, 2));
        pointGroup2->add(new Line(2, 2, 3, 3));
        pointGroup2->add(new Circle(1, 1, 2));
        pointGroup2->add(new Circle(2, 2, 3));

        allPointGroups->draw();

        std::cout << std::endl;
    }
}