
#include "window.h"


Window::Window()
{
    sz.width = 4;
    sz.height = 5;

    pos.x = 0;
    pos.y = 0;
};

void Window::set_position(position newPosition)
{
    if ((newPosition.x >= 0)&&(newPosition.y>=0)) pos = newPosition;
}; 

void Window::set_size(size newSize)
{
    if ((newSize.height > 0)&&(newSize.width>0)) sz = newSize;    
}

size Window::get_size()
{
    return sz;
};

position Window::get_posiziton()
{
    return pos;
};