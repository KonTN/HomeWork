#include <vector>
#include <iostream>

void sort_mass(std::vector<int> &mass){
    for (int i=0;i<mass.size();i++){
        for (int j=mass.size()-1;j>i;j--){
            if (abs(mass[j])<abs(mass[j-1])){
                int buff = mass[j];
                mass[j] = mass[j-1];
                mass[j-1] = buff;
            }
        }
    }
}


int main(){
    std::vector<int> mass = {-100,-50, -5, 1, 10, 15};
    sort_mass(mass);
    for (int i : mass) std::cout << i << ' ';
    std::cout << std::endl;
    system("pause");
    return 0;
}