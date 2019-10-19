#pragma once
#include "Image.hpp"
#include <iostream>

class Point : public Image
{
private:
  int x, y;

public:
  Point(int x, int y);
  void draw(void);
  void move(int x, int y);
  void scale(double scaleBy);
  double area(void);
  void fileOut(std::ofstream& out);
  void fileIn(std::ifstream& in);
  int getx(void);
  int gety(void);
};