#include "track.h"


Track::Track(std::string data_line)
{
    std::stringstream dataStr;
    dataStr << data_line;

    dataStr >> name;
    dataStr >> duration.min;
    char dummyDelim;
    dataStr >> dummyDelim;
    dataStr >> duration.sek;

    dataStr >> date.tm_year;
    dataStr >> dummyDelim;
    dataStr >> date.tm_mon;
    dataStr >> dummyDelim;
    dataStr >> date.tm_mday;

    if (dataStr.fail())
    {
        name = "EMPTY_NAME";
        duration.min = 0;
        duration.sek = 0;
        std::time_t dTime = std::time(nullptr);
        std::tm *dates = localtime(&dTime);
        date = *dates;
    }
};



Track::Track(std::string _name,int _duration,std::tm _date)
{
    if (!_name.empty())name = _name;
    else name = "EMPTY_NAME";

    duration.min = _duration/60;
    duration.sek = _duration%60;
    
    date = _date;
};


std::string Track::get_name()
{
    return name;
};

std::string Track::get_duaration_str()
{
    std::string retStr = "";
    retStr+=std::to_string(duration.min);
    retStr.push_back(':');
    retStr+=std::to_string(duration.sek);

    return retStr;
};

std::string Track::get_date_str()
{
    std::string retStr = "";
    retStr += std::to_string(date.tm_mday);
    retStr.push_back('/');
    retStr += std::to_string(date.tm_mon);
    retStr.push_back('/');
    retStr += std::to_string(date.tm_year);
    
    return retStr;
}