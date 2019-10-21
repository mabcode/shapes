#include "Triangle.hpp"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
}
void Triangle::draw(void)
{
    std::cout << "Triangle from: X1:" << x1 << " Y1:" << y1 << "  TO  X2:" << x2 << " Y2:" << y2 << "  TO  X3:" << x3 << " Y3:" << y3 << std::endl;
}

void Triangle::move(int x, int y)
{
    this->x1 += x;
    this->x2 += x;
    this->x3 += x;
    this->y1 += y;
    this->y2 += y;
    this->y3 += y;
}

void Triangle::scale(double scaleBy)
{
    //could get more accurate
    this->x2 *= scaleBy;
    this->y3 *= scaleBy;
}

double Triangle::area(void)
{
    double tempHeight = y3 - y1;
    return (((x2 - x1) * tempHeight) / 2);
}

void Triangle::fileOut(std::ofstream &out)
{
    out << "Triangle " << this->x1 << " " << this->y1 << " " << this->x2 << " " << this->y2 << " " << this->x3 << " " << this->y3 << std::endl;
}

void Triangle::fileIn(std::ifstream &in)
{
    in >> this->x1 >> this->y1 >> this->x2 >> this->y2 >> this->x3 >> this->y3;
}

int Triangle::getx1(void)
{
    return this->x1;
}
int Triangle::getx2(void)
{
    return this->x2;
}
int Triangle::getx3(void)
{
    return this->x3;
}
int Triangle::gety1(void)
{
    return this->y1;
}
int Triangle::gety2(void)
{
    return this->y2;
}
int Triangle::gety3(void)
{
    return this->y3;
}