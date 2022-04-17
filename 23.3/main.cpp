#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <unistd.h>


int main(int argc, char** argv)
{
    std::cout << "Timer program \n Enter time (MM:SS) : ";
    
    
    std::time_t dTime = std::time(nullptr);
    std::tm *date = localtime(&dTime);
    std::cin >> std::get_time(date,"%M:%S");
    
    std::time_t sTime = std::time(nullptr);
    std::time_t aimTime = sTime + date->tm_min*60+date->tm_sec;
    std::time_t diff = 0;
    do {
        std::time_t cTime = std::time(nullptr);
        diff = (std::time_t)std::difftime(aimTime,cTime);
        date = localtime(&diff);
        std::cout << date->tm_min << ":" << date->tm_sec <<std::endl;     
        sleep(1);
    } while (diff > 0);

    std::cout << "DING!DING!DING!" << std::endl;

    return 0;
}