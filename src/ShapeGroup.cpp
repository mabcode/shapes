#include "ShapeGroup.hpp"

ShapeGroup::ShapeGroup(std::string name)
{
    this->imgName = name;
}

void ShapeGroup::add(Image *img)
{
    imgPieces.push_back(img);
}

void ShapeGroup::remove(Image *img)
{
    //find image in vector and remove it
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

    out.open(imgName);

    for (auto &iter : this->imgPieces)
    {
        iter->fileOut(out);
    }
    out.close();
}
void ShapeGroup::fileIn(std::ifstream& in)
{

    in.open(imgName);

    for (auto &iter : this->imgPieces)
    {
        iter->fileIn(in);
    }
    in.close();
}

std::string ShapeGroup::getName(void)
{
    return imgName;
}
