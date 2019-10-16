#include "Circle.hpp"

Circle::Circle(int x, int y, double rad)
{
    this->x = x;
    this->y = y;
    this->rad = rad;
}

void Circle::draw()
{
    std::cout << "Cirle at X :" << x << " Y :" << y << " With Radious " << rad << std::endl;
}

void Circle::move(int x, int y){
    this->x+=x;
    this->y+=y;
}