#pragma once 

#include <string>
#include "window.h"


class Sqreen
{
    public:
        Sqreen(int width,int height);
        std::string print_sqr();
        void move_window(int x,int y);
        void resize_window(int width,int height);
    private:
        size sqrSz;
        Window wnd;
        
};