#pragma once
#include <fstream>

class Shape {
    private:

    public:
        virtual void add(Shape *img);
        virtual void remove(int imgIndex);
        virtual Shape* getImage(int getImg);
        virtual void move(int x , int y);
        virtual void computeArea(Shape *img);
        virtual void scale(double scaleBy);
        virtual double area();
        virtual void draw();
        virtual void writeToFile(std::ofstream& out);
        virtual void readFromFile(std::ifstream& in);
        virtual int getSize(void);
        
};