#include "gpu.h"




void gpu::print(const std::vector<int> &ram)
{
    for (int i: ram) std::cout << i << " ";
    std::cout << std::endl;
}