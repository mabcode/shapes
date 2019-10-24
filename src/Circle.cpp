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

void Circle::move(int x, int y)
{
    this->x += x;
    this->y += y;
}

void Circle::scale(double scaleBy)
{
    this->rad *= scaleBy;
}

double Circle::area(void)
{
    return (PI * (rad * rad));
}

void Circle::writeToFile(std::ofstream &out)
{
    out << "Circle " << this->x << " " << this->y << " " << this->rad << std::endl;
}

void Circle::readFromFile(std::ifstream &in)
{
    in >> this->x >>this->y >>this->rad;
}

int Circle::getx(void)
{
    return this->x;
}
int Circle::gety(void)
{
    return this->y;
}
double Circle::getRad(void)
{
    return this->rad;
}