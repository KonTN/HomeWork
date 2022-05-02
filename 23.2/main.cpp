#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <iomanip>

int main(int argc, char** argv)
{
    std::map<int,std::vector<std::string>> bMap; // birthday map <date (in days from year start [0-365]), name-day list>
    std::map<int,std::tm> dMap; // day of the year to date map;

    std::cout << "command list: 'friend_name YYYY/MM/DD' - for add birthday in birthday list" << std::endl;
    std::cout << "              'end' - for start closest birthday calculation" << std::endl; 
    

    std::string command;
    do {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "end") continue;

        // remember potencial name 
        std::string name = command;

        // create dummy tm struct to parse date from std::cin
        std::time_t dtime = std::time(nullptr);
        std::tm* dymmyDate = std::localtime(&dtime);
        std::cin >> std::get_time(dymmyDate,"%Y/%m/%d"); // try get date in right format
        std::mktime(dymmyDate);
        if (std::cin.good()) // if get_time() does`t trow bad flag
        {
            int days = dymmyDate->tm_yday;
            if (bMap.count(days)) // if that date already in bMap
            {
                bMap[days].push_back(name); 
            }
            else {
                std::pair<int,std::vector<std::string>> dummyPair;
                dummyPair.first = days;
                dummyPair.second.push_back(name);

                bMap.insert(dummyPair);
                dMap.insert(std::make_pair(days,*dymmyDate));
            }

            continue;
        }

        std::cout << "Error: wrong command, try again "<< std::endl;
        std::cin.clear();
        std::string temp;
        std::getline(std::cin,temp);

    } while (command != "end");

    // get current date
    std::time_t curtime = std::time(nullptr);
    std::tm* curDate = std::localtime(&curtime);
    int curDay = curDate->tm_yday;

    for (auto &pr : bMap)
    {
        if (pr.first == curDay)
        {
            std::cout << "Congrats, ";
            for (std::string s : pr.second) std::cout << s << ' ';
            std::cout << "happy birthday!!!" << std::endl;   

            break;
        }

        if (pr.first > curDay)
        {              
            std::cout << "Closest birthday - " << std::put_time(&dMap[pr.first],"%m/%d") << " ( ";
            for (std::string s : pr.second) std::cout << s << ' ';
            std::cout << ")" << std::endl;

            break;
        }
        else {
            // copy all already happend birthdays to the new year 
            // (to calculate closest birthday if all birthday allready happend)
            std::pair<int,std::vector<std::string>> copyPairb = pr;
            copyPairb.first += 365;
            bMap.insert(copyPairb);

            std::pair<int,std::tm> copyPaird;
            copyPaird.first = dMap.find(pr.first)->first + 365;
            copyPaird.second = dMap.find(pr.first)->second;
            dMap.insert(copyPaird);
        }
    }
    
    return 0;
}