#pragma once
#include "Shape.hpp"
#include <iostream>

class Point : public Shape
{
private:
  int x, y;

public:
  Point(int x, int y);
  void draw(void);
  void move(int x, int y);
  void writeToFile(std::ofstream& out);
  void readFromFile(std::ifstream& in);
  int getx(void);
  int gety(void);
};