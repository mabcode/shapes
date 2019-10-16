#pragma once

class Image {
    private:

    public:
        virtual void add(Image *img);
        virtual void remove(Image *img);
        virtual Image* getImage(int getImg);
        virtual void move(Image *img);
        virtual void computeArea(Image *img);
        virtual void scale(Image *img);
        virtual void draw();
        
        
};