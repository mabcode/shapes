#include "Rectangle.hpp"

Rectangle::Rectangle(int x1, int y1, int x2, int y2, double height)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->height = height;
}
void Rectangle::draw(void)
{
    std::cout << "Line from: X1:" << x1 << " Y1:" << y1 << "  TO  X2:" << x2 << " Y2:" << y2 << " Height:" << height<< std::endl;
}

void Rectangle::move(int x, int y)
{
    this->x1 += x;
    this->x2 += x;
    this->y1 += y;
    this->y2 += y;
}

void Rectangle::scale(double scaleBy)
{
    this->x2 *= scaleBy;
    this->height *=scaleBy;
}

double Rectangle::area(void)
{   
    int tempWidth = (this->x2 -this->x1);
    return (this->height*tempWidth);
}

void Rectangle::fileOut(std::ofstream &out)
{
    out << "Line " << this->x1 << " " << this->y1 << " " << this->x2 << " " << this->y2 <<" " << this->height << std::endl;
}

void Rectangle::fileIn(std::ifstream &in)
{
    in >> this->x1 >> this->y1 >> this->x2 >> this->y2 >> this->height;
}

int Rectangle::getx1(void)
{
    return this->x1;
}
int Rectangle::getx2(void)
{
    return this->x2;
}
int Rectangle::gety1(void)
{
    return this->y1;
}
int Rectangle::gety2(void)
{
    return this->y2;
}
double Rectangle::getHeight(void)
{
    return this->height;
}