#pragma once

#include <string>
#include <iomanip>
#include <ctime>


class Track
{
    public:
        Track(std::string info); //info format "name hh:mm:ss DD/MM/YYYY"  
        std::string get_info();  //               ^- track name 
                                 //                      ^- track duration
                                 //                                ^= date of track creation
        std::string get_name();
    private:
        std::string name;
        std::tm date;
};