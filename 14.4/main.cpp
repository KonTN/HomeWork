#include <vector>
#include <iostream>

int main(){
    std::vector<int> mass = {-100,-50, -5, 1, 10, 15};

    int positive_poss = 0;
    int negative_poss = 0;

    // find first postive number 
    for (int i=0;i<mass.size();i++) if (mass[i]>=0) {positive_poss =  i; break;}
     // first negative would be
    negative_poss = positive_poss -1;

    while ((negative_poss>=0)||(positive_poss < mass.size())){
        if ((negative_poss >= 0)&&(abs(mass[positive_poss])>abs(mass[negative_poss]))){
            std::cout << mass[negative_poss] << ' ';
            negative_poss --;
        }
        else if (positive_poss<mass.size()) {
            std::cout << mass[positive_poss] << ' ';
            positive_poss ++;               
        }
    }
    
    std::cout << std::endl;
    return 0;
}
