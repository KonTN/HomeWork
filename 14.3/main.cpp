#include <iostream>
#include <vector>


void sort_mass(std::vector<int> &mass){
    for (int i=0;i<mass.size();i++){
        for (int j=mass.size()-1;j>i;j--){
            if (mass[j]<mass[j-1]){
                int buff = mass[j];
                mass[j] = mass[j-1];
                mass[j-1] = buff;
            }
        }
    }
}


int main(){
    std::vector<int> num;
    int buff;
    do{
        do{
        std::cin >> buff;
        num.push_back(buff);
        } while (!((buff==-1)||(buff==-2)));
        num.pop_back(); // delete -1 or -2 from mass;
        sort_mass(num);
        system("cls");
        std::cout << std::endl;
        for (int i: num) std::cout << i << ' ';
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout<< num[4] << std::endl;
    }while (buff!=-2);
    return 0;
}