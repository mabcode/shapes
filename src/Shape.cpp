#include "Shape.hpp"

void Shape::add(Shape *img) {}
void Shape::remove(int imgIndex) {}
Shape *Shape::getImage(int getImg) { return new Shape; }
void Shape::move(int x, int y) {}
void Shape::computeArea(Shape *img) {}
void Shape::scale(double scaleBy) {}
double Shape::area() {return 0;}
void Shape::draw() {}
void Shape::writeToFile(std::ofstream& out){}
void Shape::readFromFile(std::ifstream& in){}
int Shape::getSize(void){return 0;}