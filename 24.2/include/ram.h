#pragma once

#include<vector>

namespace ram 
{
    void write(std::vector<int> &data, const std::vector<int> &memory);
    void read(const std::vector<int> &data, std::vector<int> &memory);
}