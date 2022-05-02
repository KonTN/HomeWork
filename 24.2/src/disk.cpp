#include "disk.h"





int disk::load(std::vector<int> &ram , const std::string path)
{
    std::ifstream save;
    save.open(path);
    
    if (!save.is_open()) return 1;
    
    std::vector<int> savedRam;
    while (!save.eof())
    {   
        int dummy;
        save >> dummy;
        savedRam.push_back(dummy);
    }
    save.close();

    for (int i =0;i<ram.size();i++) ram[i] = savedRam[i];
    return 0;
}

int disk::save(const std::vector<int> &ram, const std::string path)
{
    std::ofstream save;
    save.open(path);
    
    if (!save.is_open()) return 1;
    if (ram.size() != 8) return 1;

    for (int i: ram) save << i << " ";
    save.close();
    return 0; 
}