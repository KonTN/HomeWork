#pragma once

#include<fstream>
#include<vector>
#include<string>

namespace disk
{
    int save(const std::vector<int> &ram, const std::string path = "data.txt");
    int load(std::vector<int> &ram, const std::string path = "data.txt");  
} 


