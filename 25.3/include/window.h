#pragma once 

#include <string>

struct position
{
    int x;
    int y;
};

struct size
{
    int width;
    int height;
};

class Window
{
    public:
        Window();
        void set_size(size newSize);
        void set_position(position newPosition);
        size get_size();
        position get_posiziton();
    private:
        size sz;
        position pos;
};