#include "Line.hpp"

Line::Line(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}
void Line::draw(void)
{
    std::cout << "Line from: X1:" << x1 << " Y1:" << y1 << "  TO  X2:" << x2 << " Y2:" << y2 << std::endl;
}

void Line::move(int x, int y)
{
    this->x1 += x;
    this->x2 += x;
    this->y1 += y;
    this->y2 += y;
}

void Line::scale(double scaleBy)
{
    this->x2 *= scaleBy;
}