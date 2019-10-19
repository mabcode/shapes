#pragma once
#include "Image.hpp"
#include <string>
#include <iostream>

#include <vector>

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
    std::string getName(void);
};