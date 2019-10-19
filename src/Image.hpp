#pragma once
#include <fstream>

class Image {
    private:

    public:
        virtual void add(Image *img);
        virtual void remove(Image *img);
        virtual Image* getImage(int getImg);
        virtual void move(int x , int y);
        virtual void computeArea(Image *img);
        virtual void scale(double scaleBy);
        virtual double area();
        virtual void draw();
        virtual void fileOut(std::ofstream& out);
        virtual void fileIn(std::ifstream& in);
        
};