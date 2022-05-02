#include "ram.h"



void ram::read(const std::vector<int> &data,std::vector<int> &memory)
{
    // find smallest
    int smallest = data.size();
    if (memory.size() < smallest) smallest = memory.size();

    memory.clear();
    for (int i=0;i<smallest;i++)
    {
        memory[i] = data[i];
    }
};

void ram::write(std::vector<int> &data,const  std::vector<int> &memory)
{
    // find smallest
    int smallest = data.size();
    if (memory.size() < smallest) smallest = memory.size();

    for (int i=0;i<smallest;i++)
    {
        data[i] = memory[i];
    }
};