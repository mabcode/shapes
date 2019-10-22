#include <catch2/catch.hpp>

#include "../ShapeGroup.cpp"
#include "../Image.cpp"
#include <fstream>

TEST_CASE("Checking that Shape Group and composite", "[composite]")
{
    SECTION("Checking the constructor")
    {
        ShapeGroup *composite1 = new ShapeGroup("point group 1");
        CHECK(composite1->getName() == "point group 1");

        ShapeGroup *composite2 = new ShapeGroup("point group 2");
        CHECK(composite2->getName() == "point group 2");

        delete composite1;
        delete composite2;
    }

    SECTION("Checking composite move() on Point, Line, Circle, Triangle, Rectangle")
    {
        Image *pointGroup = new ShapeGroup("point group");
        Image *lineGroup = new ShapeGroup("line group");
        Image *circleGroup = new ShapeGroup("circle group");
        Image *rectangleGroup = new ShapeGroup("rectangle group");
        Image *triangleGroup = new ShapeGroup("triangle group");

        Image *allPointGroups = new ShapeGroup("allPoints");

        allPointGroups->add(pointGroup);
        pointGroup->add(new Point(1, 2));
        pointGroup->add(new Point(4, 5));
        pointGroup->add(new Point(6, 7));

        allPointGroups->add(lineGroup);
        lineGroup->add(new Line(1, 2, 3, 4));
        lineGroup->add(new Line(5, 6, 7, 8));

        allPointGroups->add(circleGroup);
        circleGroup->add(new Circle(1, 2, 3));
        circleGroup->add(new Circle(5, 6, 7));

        allPointGroups->add(triangleGroup);
        triangleGroup->add(new Triangle(1, 0, 3, 0, 2, 2));
        triangleGroup->add(new Triangle(5, 0, 7, 0, 6, 6));

        allPointGroups->add(rectangleGroup);
        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));
        rectangleGroup->add(new Rectangle(5, 0, 7, 0, 6));

        allPointGroups->move(10, 10);

        auto temp1 = static_cast<Point *>(pointGroup->getImage(0));
        auto temp2 = static_cast<Point *>(pointGroup->getImage(1));
        auto temp3 = static_cast<Point *>(pointGroup->getImage(2));

        CHECK(temp1->getx() == 11);
        CHECK(temp1->gety() == 12);
        CHECK(temp2->getx() == 14);
        CHECK(temp2->gety() == 15);

        auto temp4 = static_cast<Line *>(lineGroup->getImage(0));
        auto temp5 = static_cast<Line *>(lineGroup->getImage(1));

        CHECK(temp4->getx1() == 11);
        CHECK(temp4->gety1() == 12);
        CHECK(temp4->getx2() == 13);
        CHECK(temp4->gety2() == 14);
        CHECK(temp5->getx1() == 15);
        CHECK(temp5->gety1() == 16);
        CHECK(temp5->getx2() == 17);
        CHECK(temp5->gety2() == 18);

        auto temp6 = static_cast<Circle *>(circleGroup->getImage(0));
        auto temp7 = static_cast<Circle *>(circleGroup->getImage(1));

        CHECK(temp6->getx() == 11);
        CHECK(temp6->gety() == 12);
        CHECK(temp6->getRad() == 3);
        
        CHECK(temp7->getx() == 15);
        CHECK(temp7->gety() == 16);
        CHECK(temp7->getRad() == 7);

        auto temp8 = static_cast<Triangle *>(triangleGroup->getImage(0));
        auto temp9 = static_cast<Triangle *>(triangleGroup->getImage(1));

        CHECK(temp8->getx1() == 11);
        CHECK(temp8->gety1() == 10);
        CHECK(temp8->getx2() == 13);
        CHECK(temp8->gety2() == 10);
        CHECK(temp8->getx3() == 12);
        CHECK(temp8->gety3() == 12);

        CHECK(temp9->getx1() == 15);
        CHECK(temp9->gety1() == 10);
        CHECK(temp9->getx2() == 17);
        CHECK(temp9->gety2() == 10);
        CHECK(temp9->getx3() == 16);
        CHECK(temp9->gety3() == 16);

        auto temp10 = static_cast<Rectangle *>(rectangleGroup->getImage(0));
        auto temp11 = static_cast<Rectangle *>(rectangleGroup->getImage(1));

        CHECK(temp10->getx1() == 11);
        CHECK(temp10->gety1() == 10);
        CHECK(temp10->getx2() == 13);
        CHECK(temp10->gety2() == 10);
        CHECK(temp10->getHeight() == 5);

        CHECK(temp11->getx1() == 15);
        CHECK(temp11->gety1() == 10);
        CHECK(temp11->getx2() == 17);
        CHECK(temp11->gety2() == 10);
        CHECK(temp11->getHeight() == 6);
    
    }

    // SECTION("Checking groups of points and lines")
    // {
    //     Image *pointGroup1 = new ShapeGroup("point and Line group 1");
    //     Image *pointGroup2 = new ShapeGroup("point and Line group 2");

    //     Image *allPointGroups = new ShapeGroup("Points and lines");

    //     allPointGroups->add(pointGroup1);
    //     pointGroup1->add(new Point(1, 2));
    //     pointGroup1->add(new Point(1, 2));
    //     pointGroup1->add(new Point(3, 3));
    //     pointGroup1->add(new Line(6, 6, 12, 12));
    //     pointGroup1->add(new Line(0, 1, 23, 44));

    //     allPointGroups->add(pointGroup2);
    //     pointGroup2->add(new Point(3, 3));
    //     pointGroup2->add(new Point(4, 3));
    //     pointGroup2->add(new Point(5, 3));
    //     pointGroup2->add(new Line(1, 1, 2, 2));
    //     pointGroup2->add(new Line(2, 2, 3, 3));

    //     allPointGroups->draw();
    //     allPointGroups->move(100,100);
    //     std::cout << std::endl;
    //     std::cout << "POINTS AFTER BEING MOVED \n";
    //     allPointGroups->draw();
    //     std::cout << std::endl;
    // }

    // SECTION("Checking groups of points and lines")
    // {
    //     Image *pointGroup1 = new ShapeGroup("point, Line, and Circles group 1");
    //     Image *pointGroup2 = new ShapeGroup("point, Line, and Circles group 2");

    //     Image *allPointGroups = new ShapeGroup("Points, Line, and Circles");

    //     allPointGroups->add(pointGroup1);
    //     pointGroup1->add(new Point(1, 2));
    //     pointGroup1->add(new Point(1, 2));
    //     pointGroup1->add(new Point(3, 3));
    //     pointGroup1->add(new Line(6, 6, 12, 12));
    //     pointGroup1->add(new Line(0, 1, 23, 44));
    //     pointGroup1->add(new Circle(6, 6, 12));
    //     pointGroup1->add(new Circle(0, 1, 23));

    //     allPointGroups->add(pointGroup2);
    //     pointGroup2->add(new Point(3, 3));
    //     pointGroup2->add(new Point(4, 3));
    //     pointGroup2->add(new Point(5, 3));
    //     pointGroup2->add(new Line(1, 1, 2, 2));
    //     pointGroup2->add(new Line(2, 2, 3, 3));
    //     pointGroup2->add(new Circle(1, 1, 2));
    //     pointGroup2->add(new Circle(2, 2, 3));

    //     allPointGroups->draw();
    //     allPointGroups->move(1000,1000);
    //     std::cout << std::endl;
    //     std::cout << "POINTS AFTER BEING MOVED \n";
    //     allPointGroups->draw();
    //     std::cout << std::endl;
    // }
}