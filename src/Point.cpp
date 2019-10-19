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

void Point::scale(double scaleBy)
{

}

double Point::area(void)
{
    return 0;
}

int Point::getx(void){
    return this->x;
}
int Point::gety(void){
    return this->y;
}