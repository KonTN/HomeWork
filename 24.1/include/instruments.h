#pragma once

#include<vector>
#include<string>
#include <sstream>
#include <iostream>


namespace ins 
{


    struct point
    {
        double x=0;
        double y=0;
    };


    const std::vector<std::string> command_list = {"scalpel","hemostat","tweezers","suture"};
    // command_list must be the same as movement::movementType enum

    struct movement
    {
        enum movementType 
        {
            UNKNOWN = -1,
            SCALPEL,
            HEMOSTAT,
            TWEEZERS,
            SUTURE
        };
        movementType type;
        point start;
        point end;
    };

   movement make_move(int argc, std::vector<std::string> argv);
   void print_move(movement);
}

