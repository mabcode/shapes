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

    SECTION("Checking composite scale() on Point, Line, Circle, Triangle, Rectangle")
    {
        Image *pointGroup = new ShapeGroup("point group");
        Image *lineGroup = new ShapeGroup("line group");
        Image *circleGroup = new ShapeGroup("circle group");
        Image *rectangleGroup = new ShapeGroup("rectangle group");
        Image *triangleGroup = new ShapeGroup("triangle group");

        Image *allPointGroups = new ShapeGroup("allPoints");

        allPointGroups->add(pointGroup);
        pointGroup->add(new Point(1, 2));

        allPointGroups->add(lineGroup);
        lineGroup->add(new Line(1, 2, 3, 2));

        allPointGroups->add(circleGroup);
        circleGroup->add(new Circle(1, 2, 3));

        allPointGroups->add(triangleGroup);
        triangleGroup->add(new Triangle(1, 0, 3, 0, 2, 2));

        allPointGroups->add(rectangleGroup);
        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));

        allPointGroups->scale(2);

        auto temp1 = static_cast<Point *>(pointGroup->getImage(0));
        auto temp2 = static_cast<Line *>(lineGroup->getImage(0));
        auto temp3 = static_cast<Circle *>(circleGroup->getImage(0));
        auto temp4 = static_cast<Triangle *>(triangleGroup->getImage(0));
        auto temp5 = static_cast<Rectangle *>(rectangleGroup->getImage(0));

        CHECK(temp1->getx() == 1);
        CHECK(temp1->gety() == 2);

        CHECK(temp2->getx1() == 1);
        CHECK(temp2->gety1() == 2);
        CHECK(temp2->getx2() == 6);
        CHECK(temp2->gety2() == 2);

        CHECK(temp3->getx() == 1);
        CHECK(temp3->gety() == 2);
        CHECK(temp3->getRad() == 6);
    }

    SECTION("Checking composite area() on Point, Line, Circle, Triangle, Rectangle")
    {
        Image *pointGroup = new ShapeGroup("point group");
        Image *lineGroup = new ShapeGroup("line group");
        Image *circleGroup = new ShapeGroup("circle group");
        Image *rectangleGroup = new ShapeGroup("rectangle group");
        Image *triangleGroup = new ShapeGroup("triangle group");

        Image *allPointGroups = new ShapeGroup("allPoints");

        allPointGroups->add(pointGroup);
        pointGroup->add(new Point(1, 2));

        allPointGroups->add(lineGroup);
        lineGroup->add(new Line(1, 2, 3, 2));

        allPointGroups->add(circleGroup);
        circleGroup->add(new Circle(1, 2, 3));

        allPointGroups->add(triangleGroup);
        triangleGroup->add(new Triangle(1, 0, 3, 0, 2, 2));

        allPointGroups->add(rectangleGroup);
        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));

        int area =0;

        area = allPointGroups->area();

        CHECK(area == 40);

        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));
        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));

        area = allPointGroups->area();

        CHECK(area == 60);

        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));
        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));

        area = allPointGroups->area();

        CHECK(area == 80);

        allPointGroups->add(triangleGroup);
        triangleGroup->add(new Triangle(1, 0, 3, 0, 2, 2));

        area = allPointGroups->area();

        CHECK(area == 86);
        
    }

    SECTION("Checking composite fileOut() and fileIn() on Point, Line, Circle, Triangle, Rectangle")
    {
        Image *pointGroup = new ShapeGroup("point group");
        Image *lineGroup = new ShapeGroup("line group");
        Image *circleGroup = new ShapeGroup("circle group");
        Image *rectangleGroup = new ShapeGroup("rectangle group");
        Image *triangleGroup = new ShapeGroup("triangle group");

        Image *allPointGroups = new ShapeGroup("allPoints");

        allPointGroups->add(pointGroup);
        pointGroup->add(new Point(1, 2));

        allPointGroups->add(lineGroup);
        lineGroup->add(new Line(1, 2, 3, 2));

        allPointGroups->add(circleGroup);
        circleGroup->add(new Circle(1, 2, 3));

        allPointGroups->add(triangleGroup);
        triangleGroup->add(new Triangle(1, 0, 3, 0, 2, 2));

        allPointGroups->add(rectangleGroup);
        rectangleGroup->add(new Rectangle(1, 0, 3, 0, 5));

        std::ofstream out;
        out.open("testComposite.txt");
        allPointGroups->fileOut(out);
        out.close();

        Image *allPointGroups2 = new ShapeGroup("allPoints2");
        std::ifstream in;
        in.open("testComposite.txt");
        allPointGroups2->fileIn(in);
        in.close();

        out.open("testComposite2.txt");
        allPointGroups2->fileOut(out);
        out.close();

        auto temp1 = static_cast<Point *>(allPointGroups2->getImage(0));
        auto temp2 = static_cast<Line *>(allPointGroups2->getImage(1));
        auto temp3 = static_cast<Circle *>(allPointGroups2->getImage(2));
        auto temp4 = static_cast<Triangle *>(allPointGroups2->getImage(3));
        auto temp5 = static_cast<Rectangle *>(allPointGroups2->getImage(4));

        CHECK(temp1->getx() == 1);
        CHECK(temp1->gety() == 2);

        CHECK(temp2->getx1() == 1);
        CHECK(temp2->gety1() == 2);
        CHECK(temp2->getx2() == 3);
        CHECK(temp2->gety2() == 2);

        CHECK(temp3->getx() == 1);
        CHECK(temp3->gety() == 2);
        CHECK(temp3->getRad() == 3);

        CHECK(temp4->getx1() == 1);
        CHECK(temp4->gety1() == 0);
        CHECK(temp4->getx2() == 3);
        CHECK(temp4->gety2() == 0);
        CHECK(temp4->getx3() == 2);
        CHECK(temp4->gety3() == 2);

        CHECK(temp5->getx1() == 1);
        CHECK(temp5->gety1() == 0);
        CHECK(temp5->getx2() == 3);
        CHECK(temp5->gety2() == 0);
        CHECK(temp5->getHeight() == 5);

    }
}
