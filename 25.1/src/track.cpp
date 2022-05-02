#include "track.h"

#include <sstream>




Track::Track(std::string info)
{
    
    std::stringstream infoStm;
    infoStm << info;

    // parse info stream
    infoStm >> name;
    bool fail = infoStm.fail();
    infoStm >> std::get_time(&date, "%H:%M:%S %d/%m/%Y");
    fail = infoStm.fail();

    if (infoStm.fail())
    {
        name = "ERROR_NAME";
        date.tm_min = 1;
        date.tm_hour = 1;
        date.tm_sec  = 1;
        date.tm_mday = 1;
        date.tm_mon = 1;
        date.tm_year = 1;
    }
}


std::string Track::get_info()
{
    std::stringstream retStm;
    retStm << name << " " << std::put_time(&date, "%H:%M:%S %d/%m/%Y");
    return retStm.str();
}

std::string Track::get_name()
{
    return name;
}