#include "ShapeGroup.hpp"

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
    return (Image *)imgPieces.at(imgIndex);
}

void ShapeGroup::draw(void)
{
    for (auto &iter : this->imgPieces)
    {
        iter->draw();
    }
}
