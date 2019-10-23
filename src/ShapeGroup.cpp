#include "ShapeGroup.hpp"

ShapeGroup::ShapeGroup(std::string name)
{
    this->imgName = name;
}

void ShapeGroup::add(Image *img)
{
    imgPieces.push_back(img);
}

void ShapeGroup::remove(int imgIndex)
{
    imgPieces.erase(imgPieces.begin()+(imgIndex-1));
}

Image *ShapeGroup::getImage(int imgIndex)
{
    return imgPieces.at(imgIndex);
}

void ShapeGroup::draw(void)
{
    std::cout << getName() << std::endl;

    for (auto &iter : this->imgPieces)
    {
        iter->draw();
    }
}

void ShapeGroup::move(int x, int y)
{
    for (auto &iter : this->imgPieces)
    {
        iter->move(x, y);
    }
}

void ShapeGroup::scale(double scaleBy)
{
    for (auto &iter : this->imgPieces)
    {
        iter->scale(scaleBy);
    }
}

double ShapeGroup::area(void)
{
    double tempArea = 0;

    for (auto &iter : this->imgPieces)
    {
        tempArea += iter->area();
    }

    return tempArea;
}

void ShapeGroup::fileOut(std::ofstream &out)
{
    for (auto &iter : this->imgPieces)
    {
        iter->fileOut(out);
    }
}
void ShapeGroup::fileIn(std::ifstream &in)
{
    std::string tempClass;

    int x, y, x2, y2, x3, y3, height;
    double rad;

    while (!in.eof())
    {
        in >> tempClass;
        if (tempClass == "Point")
        {
            in >> x >> y;
            imgPieces.push_back(new Point(x, y));
        }
        else if (tempClass == "Line")
        {
            in >> x >> y >> x2 >> y2;
            imgPieces.push_back(new Line(x, y, x2, y2));
        }
        else if (tempClass == "Circle")
        {
            in >> x >> y >> rad;
            imgPieces.push_back(new Circle(x, y, rad));
        }
        else if (tempClass == "Triangle")
        {
            in >> x >> y >> x2 >> y2 >> x3 >> y3;
            imgPieces.push_back(new Triangle(x, y, x2, y2, x3, y3));
        }
        else if (tempClass == "Rectangle")
        {
            in >> x >> y >> x2 >> y2 >> height;
            imgPieces.push_back(new Rectangle(x, y, x2, y2, height));
        }
    }

}

std::string ShapeGroup::getName(void)
{
    return imgName;
}

int ShapeGroup::getSize(void){
    return imgPieces.size();
}
