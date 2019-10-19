#pragma once
#include "Image.hpp"

#include <iostream>

class Circle : public Image
{
  private:
    int x, y;
    double rad;

  public:
    Circle(int x, int y, double rad);
    void draw(void);
    void move(int x, int y);
    void scale(double scaleBy);
};