#include "sqreen.h"



Sqreen::Sqreen(int width,int height)
{
    if ((width > 0)&&(height >0))
    {
        sqrSz.width = width;
        sqrSz.height = height;
        return;
    }
    
    sqrSz.width = 1;
    sqrSz.height = 1;
};

std::string Sqreen::print_sqr()
{
    std::string retStr;
    for ( int i=0; i<sqrSz.height; i++)
    {
        int x = wnd.get_posiziton().x;
        int w = wnd.get_size().width;
        for( int j=0; j<sqrSz.width; j++)
        {
            int y = wnd.get_posiziton().y;
            int h = wnd.get_size().height;

            if ((i<x)||(i>x+w)||(j<y)||(j>y+h))
            {
                retStr.push_back('.');
                continue;
            } 

            retStr.push_back('*');
        }
        retStr.push_back('\n');
    }
    return retStr;
};

void Sqreen::move_window(int x, int y)
{
    if ((x<sqrSz.height)&&(y<sqrSz.width))
    {
        wnd.set_position({x,y});
    }
};

void Sqreen::resize_window(int width, int height)
{
        wnd.set_size({width,height});
};

