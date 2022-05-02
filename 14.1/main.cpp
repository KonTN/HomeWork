#include <iostream>
# include <vector>
std::vector<int> mass = {-2,1,-3,4,-1,2,1,-5,4};
short coord[2] = {0,(short)mass.size()};

int main(){
    int bSumm = mass[0];
    int summ = 0;
    for (int i=0;i<mass.size();i++){
        summ += mass[i];
        if (summ < 0) { summ = 0; coord[0] = i+1; }
        if (summ > bSumm) { bSumm = summ; coord[1] = i;}
    }

    
    std::cout << "the biggest sequens starts from : " << coord[0] << " and ends with : " << coord[1] << std::endl;
    system("pause");   
    return 0;
}