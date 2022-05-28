#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "sqreen.h"

std::vector<std::string> parse_command(std::string str)
{
    std::stringstream retStm;
    std::vector<std::string> retVec;

    retStm << str;
    std::string word;
    while(!retStm.eof())
    {
        retStm >> word;
        retVec.push_back(word);
    }

    return retVec;
};

int stopi(std::string str)
{
    int retInt = 0;
    for (char c : str)
    {
        if ((c<'0')||(c>'9')) return -1;

        retInt *=10;
        retInt += c - '0';
    }
    return retInt;
};

int main()
{
    Sqreen sqr(80,50);
    std::cout << "------------------------------\n";
    std::cout << "Window sim\n";
    std::cout << "------------------------------\n";
    std::cout << "Command list: \n";
    std::cout << "\tmove x y \n";
    std::cout << "\tresize h w \n";
    std::cout << "\tdispaly\n";
    std::cout << "\tclose\n";
    std::cout << "------------------------------\n";
    
    std::string commandLine;
    std::vector<std::string> commands;
    do {
        std::cout << "winSim> ";
        std::getline(std::cin, commandLine);
        commands = parse_command(commandLine);
        
        if ((commands.front() == "move")&&(commands.size() == 3))
        {
            // if 'x y' or 'h w' not a positive integer values; 
            int x = stopi(commands[1]);
            int y = stopi(commands[2]);
            if ((x != -1)&&(y!= -1))
            {
                sqr.move_window(x,y);
                continue;
            }
            
        }
        if ((commands.front() == "resize")&&(commands.size() == 3))
        {
            // if 'x y' or 'h w' not a positive integer values; 
            int x = stopi(commands[1]);
            int y = stopi(commands[2]);
            if ((x != -1)&&(y!= -1))
            {
                sqr.resize_window(x,y);
                continue;
            }
        }
        if ((commands.front() == "display")&&(commands.size() == 1))
        {
            std::cout << sqr.print_sqr();
            continue;
        }
        if (commands.front() == "close") continue;

        std::cout << "winSim> Error: unknown command\n";
    } while(commands.front()!="close");

}