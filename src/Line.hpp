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
};