#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"
#include "ram.h"




int main(int argc, char** argv)
{
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "           simple PC sim" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout <<  "Command list: " << std::endl;
    std::cout << "  sum - to summ ram buff" << std::endl;
    std::cout << "  save - to save ram buff" << std::endl;
    std::cout << "  load - to load ram buff from hdd" << std::endl;
    std::cout << "  intput - to load ram buff from keyboard (8 in numbers)" << std::endl;
    std::cout << "  display - to print ram buff to console" << std::endl;
    std::cout << "  exit - to exit program" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Your commads: " << std::endl;
    
    std::string command;

    // setup ram
    std::vector<int> ram;
    ram.resize(8);
    for (int &i:ram) i=0;

    // setup data
    std::vector<int> data;
    data.resize(8);
    for (int &i:data) i=0;


    do {
        std::cin >> command;
        if (command == "sum")
        {
            ram::write(data,ram);
            cpu::compute(data);
            ram::read(data,ram);
        
        } else if (command == "save")
        {
            ram::write(data,ram);
            if (disk::save(data))
            {
                std::cout << "Error: save error" << std::endl;
                return 1;
            }
        
        } else if (command == "load")
        {
            if(disk::load(data))
            {
                std::cout << "Error: read error" << std::endl;
                return 1;
            }
            ram::read(data,ram);

        } else if (command == "input")
        {
            if(kbd::input(data))
            {
                std::cout << "Error: input error" << std::endl;
                return 1;
            }
            ram::read(data,ram);

        } else if (command == "display")
        {
            ram::write(data,ram);
            gpu::print(data);
        }else if (command == "exit") continue;
        else std::cout << "Unknown command" << std::endl;

    } while (command != "exit");
    
    
    return 0;
}