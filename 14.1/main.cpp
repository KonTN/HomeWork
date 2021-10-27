#include <iostream>
# include <vector>

std::vector<int> mass = {-2,1,-3,4,-1,2,1,-5,4};
short coord[2];

int main(){
    int summ = 0,buff = 0;
    for (int i=0;i<mass.size();i++){
        for (int j=i;j<mass.size();j++){
          for (int k=i;k<j;k++) buff += mass[k];
          if (buff>summ) {
              coord[0] = i; coord[1] = j-1;
              summ = buff;
          }
          buff = 0;
        }
    }


    std::cout << coord[0] << ' ' << coord[1] << std::endl;
    system("pause");






    return 0;
}