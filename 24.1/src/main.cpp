#include <iostream>
#include "instruments.h"

struct commandStr
{
    int argc;
    std::vector<std::string> argv;
};

commandStr parse_command(std::string str)
{
    commandStr retStruct;
    std::stringstream strStream;
    strStream << str;
    retStruct.argc = 0;
    
    for( ; !strStream.eof() ; retStruct.argc++)
    {
        std::string dummy;
        strStream >> dummy;
        retStruct.argv.push_back(dummy);
    }
    
    return retStruct;
};

int main(int argc, char** argv)
{
    for (int i=0;i<40;i++) std::cout << '-';
    std::cout << std::endl;
    std::cout << "surgical operation sim" << std::endl;
    for (int i=0;i<40;i++) std::cout << '-';
    std::cout << std::endl;
    std::cout << "command list: " << std::endl;
    std::cout << "  'scalpel x1:y1 x2:y2' - make a incision from x1:y1 point to x2:y2" << std::endl;
    std::cout << "  'hemostat x:y' - place a hemostat at x:y" << std::endl;
    std::cout << "  'tweezers x:y' - place a tweezers at x:y" << std::endl;
    std::cout << "  'suture x1:y1 x2:y2' - make a suture from x1:y1 point to x2:y2" << std::endl;
    for (int i=0;i<40;i++) std::cout << '-';
    std::cout << std::endl;
    std::cout << "start with scalpel as first commad to start operation" << std::endl;
    std::cout << "after suture last incision operation is considered completed and programm ends" << std::endl;
    for (int i=0;i<40;i++) std::cout << '-';
    std::cout << std::endl;
    
    std::vector<ins::movement> moveHistory;
    std::string command;
    getline(std::cin,command);

    commandStr start_command = parse_command(command); // get first command;
    

    ins::movement start_move = ins::make_move(start_command.argc,start_command.argv);
    if (start_move.type == ins::movement::movementType::UNKNOWN)
    {
        std::cout << "Error: unknown command pattern" << std::endl;
        return 1;
    }
    if (start_move.type != ins::movement::movementType::SCALPEL)
    {
        std::cout << "Error: operation shuld start with scalpel command" << std::endl;
        return 1;
    }

    moveHistory.push_back(start_move);
    ins::print_move(start_move);

    bool quit = false;
    while (!quit)
    {
        getline(std::cin,command);
        ins::movement move = ins::make_move(parse_command(command).argc,parse_command(command).argv);
         if (move.type == ins::movement::movementType::UNKNOWN)
        {
            std::cout << "Error: unknown command pattern" << std::endl;
            return 1;
        }
        
        moveHistory.push_back(move);
        
        ins::print_move(moveHistory.back());
        
        // check for finish suture
        if ((moveHistory.back().type == ins::movement::movementType::SUTURE)&&
            (moveHistory.back().start.x == moveHistory.front().start.x)&&
            (moveHistory.back().start.y == moveHistory.front().start.y)&&
            (moveHistory.back().end.x == moveHistory.front().end.x)&&
            (moveHistory.back().end.y == moveHistory.front().end.y))
        {
            quit = true;
        }
    }
    
    std::cout << "doctor successfully ends the operation" << std::endl;

    return 0;
}