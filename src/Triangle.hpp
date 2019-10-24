#pragma once
#include "Shape.hpp"

#include <iostream>

class Triangle : public Shape
{
  private:
    int x1, y1, x2, y2, x3, y3;

  public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
    void draw(void);
    void move(int x, int y);
    void scale(double scaleBy);
    double area(void);
    void writeToFile(std::ofstream &out);
    void readFromFile(std::ifstream &in);
    int getx1(void);
    int getx2(void);
    int getx3(void);
    int gety1(void);
    int gety2(void);
    int gety3(void);
};