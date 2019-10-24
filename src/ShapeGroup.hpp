#pragma once
#include "Shape.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>

#include <vector>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"


class ShapeGroup : public Shape
{
  private:
    std::string imgName;
    std::vector<Shape *> imgPieces;

  public:
    ShapeGroup(std::string name);
    void add(Shape *img);
    void remove(int imgIndex);
    Shape *getImage(int imgIndex);
    void draw(void);
    void move(int x, int y);
    void scale(double scaleBy);
    double area(void);
    void writeToFile(std::ofstream& out);
    void readFromFile(std::ifstream& in);
    std::string getName(void);
    int getSize(void);
};