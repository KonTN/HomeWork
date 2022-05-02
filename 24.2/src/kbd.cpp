#include "kbd.h"





int kbd::input(std::vector<int> &ram)
{   
    std::cin.clear();
    ram.clear();
    ram.resize(8);
    std::cout << "Please enter 8 integer numbers: ";
    for (int &i:ram) std::cin >> i;

    if(std::cin.fail()) return 1;
    return 0;
}