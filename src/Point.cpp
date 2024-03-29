#include "Point.hpp"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::draw()
{
    std::cout << "Point X : " << x << " Point Y :" << y << std::endl;
}

void Point::move(int x, int y)
{
    this->x += x;
    this->y += y;
}

void Point::writeToFile(std::ofstream &out)
{
    out << "Point " << this->x << " " << this->y << std::endl;
}
void Point::readFromFile(std::ifstream &in)
{
    in >> this->x >> this->y;
}

int Point::getx(void)
{
    return this->x;
}
int Point::gety(void)
{
    return this->y;
}