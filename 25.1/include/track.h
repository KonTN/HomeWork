#pragma once

#include<string>
#include<ctime>
#include<sstream>



class Track
{   
    public:
        Track(std::string _name,int _duration,std::tm _date);
        Track(std::string data_line);
        std::string get_name();
        std::string get_duaration_str();
        std::string get_date_str();
    private:
        struct timePattern
        {
            int min;
            int sek;
        };
        std::string name;
        timePattern duration; 
        std::tm date;
};

