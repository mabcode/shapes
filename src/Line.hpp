#pragma once
#include "Image.hpp"

#include <iostream>

class Line : public Image
{
private:
  int x1, y1, x2, y2;

public:
  Line(int x1, int y1, int x2, int y2);
  void draw(void);
  void move(int x, int y);
  void scale(double scaleBy);
  double area(void);
  void fileOut(std::ofstream& out);
  void fileIn(std::ifstream& in);
  int getx1(void);
  int getx2(void);
  int gety1(void);
  int gety2(void);
};