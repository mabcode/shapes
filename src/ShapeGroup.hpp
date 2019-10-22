#pragma once
#include "Image.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>

#include <vector>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"


class ShapeGroup : public Image
{
  private:
    std::string imgName;
    std::vector<Image *> imgPieces;

  public:
    ShapeGroup(std::string name);
    void add(Image *img);
    void remove(Image *img);
    Image *getImage(int imgIndex);
    void draw(void);
    void move(int x, int y);
    void scale(double scaleBy);
    double area(void);
    void fileOut(std::ofstream& out);
    void fileIn(std::ifstream& in);
    std::string getName(void);
};