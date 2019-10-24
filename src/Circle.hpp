#pragma once
#include "Shape.hpp"

#include <iostream>

class Circle : public Shape
{
private:
  int x, y;
  double rad;
  const double PI = 3.14159265359;

public:
  Circle(int x, int y, double rad);
  void draw(void);
  void move(int x, int y);
  void scale(double scaleBy);
  double area(void);
  void writeToFile(std::ofstream& out);
  void readFromFile(std::ifstream& in);
  int getx(void);
  int gety(void);
  double getRad(void);
};