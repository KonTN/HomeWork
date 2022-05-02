#include "instruments.h"

int find_in_vec(const std::vector<std::string> &vec, const std::string &str)
{
    int j = -1;
    for (int i=0;i<vec.size();i++)
    {
        if (vec[i]==str) j = i;
    }

    return j;
}

int parse_coord(std::string str,ins::point &parsedPoint)
{
    std::stringstream strStream;
    strStream << str;
    
    double x;
    double y;
    char dummy;
    strStream >> x >> dummy >> y;
    

    if ((!strStream.fail())&&(dummy == ':'))
    {
        parsedPoint.x = x;
        parsedPoint.y = y;
    
        return 0;
    }
    
    return 1;
}

ins::movement ins::make_move(int argc, std::vector<std::string> argv)
{
    ins::movement retMove;
    
    // parse movement type from command 
    retMove.type = (ins::movement::movementType)find_in_vec(ins::command_list,argv[0]);
    
    // if command has only one coord
    if ((argc == 2)&&(!parse_coord(argv[1],retMove.start)))
    {
        if ((retMove.type == ins::movement::movementType::SUTURE)||
            (retMove.type == ins::movement::movementType::TWEEZERS))
        {
            return retMove;
        }
    }
    else if ((argc == 3)&&(!parse_coord(argv[1],retMove.start))&&(!parse_coord(argv[2],retMove.end)))
    {
        if ((retMove.type == ins::movement::movementType::SCALPEL)||
            (retMove.type == ins::movement::movementType::SUTURE))
        {
            return retMove;
        }
    }

    retMove.type = ins::movement::movementType::UNKNOWN;
    retMove.start.x = -1;
    retMove.start.y = -1;
    retMove.end.x = -1;
    retMove.end.y = -1;
    return retMove;
};



void ins::print_move(ins::movement move)
{
    if ((move.type == ins::movement::movementType::SCALPEL)||
    (move.type == ins::movement::movementType::SUTURE))
    {
        std::cout << "Make a " << ins::command_list[move.type] << " from ";
        std::cout << move.start.x << ":" << move.start.y << " to ";
        std::cout << move.end.x << ":" <<move.end.y << std::endl;
    }
    if ((move.type == ins::movement::movementType::HEMOSTAT)||
    (move.type == ins::movement::movementType::TWEEZERS))
    {
        std::cout << "Place a " << ins::command_list[move.type] << " at ";
        std::cout << move.start.x << ":" << move.start.y << std::endl;
    }
};