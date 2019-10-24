#pragma once
#include "Shape.hpp"

#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
// Include GLM
#include <glm/glm.hpp>

#include <./common/shader.hpp>

#include <iostream>

class Line : public Shape
{
private:
  int x1, y1, x2, y2;

public:
  Line(int x1, int y1, int x2, int y2);
  void draw(void);
  void move(int x, int y);
  void scale(double scaleBy);
  void writeToFile(std::ofstream& out);
  void readFromFile(std::ifstream& in);
  int getx1(void);
  int getx2(void);
  int gety1(void);
  int gety2(void);
};