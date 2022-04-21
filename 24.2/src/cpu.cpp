#include <cpu.h>




void cpu::compute(std::vector<int> &ram)
{
    int sum = 0 ;
    for (int i : ram) sum += i;
    for (int &i : ram) i = 0;
    ram[0] = sum;
}