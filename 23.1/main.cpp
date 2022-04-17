#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <string>

void stop_time(std::time_t &acvTime)
{
    std::time_t currentTime = std::time(nullptr);
    double diff = std::difftime(currentTime,acvTime);
    acvTime = (std::time_t)diff;
}

int main(int argc, char** argv ) {

    std::map<std::string,std::time_t> acvTimeMap;
    std::string curAcvName = ""; // current activity name
    std::string command = "";
    
    std::cout << "Command list: " << std::endl;
    std::cout << "  'begin' and activity_name - to start recording activity time" << std::endl;
    std::cout << "  'end' - to stop time recording activity time" << std::endl;
    std::cout << "  'status' - to display your activities" << std::endl;
    std::cout << "  'exit' - to exit program" << std::endl << std::endl;
    
    do {  

        std::cout << "Enter your command: ";
        std::getline(std::cin,command);

        if (command.find("begin") != std::string::npos)
        {
            // end time recording
            if (curAcvName != "") // if we start recording any activity
            {
                stop_time(acvTimeMap[curAcvName]);    
            }
            
            command.erase(0,command.find(' ')+1); // delete 'begin ' from the command line
            std::string acvName = command; // get activity name
            
            if (acvTimeMap.count(acvName)) // if we already spend some time on that activity
            {
                acvTimeMap[acvName] = std::time(nullptr) - acvTimeMap[acvName];
            }
            else 
            {
                acvTimeMap.insert(std::make_pair(acvName,std::time(nullptr)));
            }

            curAcvName = acvName;

            continue;
        }

        if (command == "end")
        {
            stop_time(acvTimeMap[curAcvName]);
            curAcvName = ""; // null current activity name

            continue;
        }

        if (command == "status")
        {
            std::cout << "already done activities: " << std::endl;

            for (auto pr : acvTimeMap)
            {
                if (pr.first != curAcvName)
                {
                    std::cout << "  " << pr.first << " - " << std::put_time(std::localtime(&pr.second), "%H:%M:%S") << std::endl;       
                }
            }
            std::cout << "current activity: " << (curAcvName == "" ? "none" : curAcvName) << std::endl;

            continue;
        } 

        if (command == "exit") continue;

        std::cout << "Unknown command" << std::endl;

    } while (command != "exit");


    return 0;
}