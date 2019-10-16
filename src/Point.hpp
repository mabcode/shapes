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
};