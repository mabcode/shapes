#pragma once
#include "Image.hpp"
#include <string>
#include <iostream>

#include <vector>

class ShapeGroup: public Image {
    private:
        std::string imgName;
        std::vector<Image*> imgPieces;
    public:
        void add(Image* img);
        void remove(Image* img);
        Image* getImage(int imgIndex);
        void draw (void);
        void move (int x, int y);
        ShapeGroup(std::string name);
        std::string getName(void);


};