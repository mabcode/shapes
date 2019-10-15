#pragma once
#include "Image.hpp"

#include <vector>

class ShapeGroup: public Image {
    private:
        std::vector<Image*> imgPieces;
    public:
        void add(Image* img);
        void remove(Image* img);
        Image* getImage(int imgIndex);
        void draw (void);


};