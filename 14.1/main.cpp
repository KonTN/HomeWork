#include <iostream>
# include <vector>
std::vector<int> mass = {2,1,3,4,1,2,1,5,4};
int coord[2];
int  summ(int start,int end){
    int resoult =  0;
    for (int i = start;i<end;i++){
        resoult += mass[i];
    }
    return resoult;
}

int main(){
// исходный массив 

    
    // fiend the biggets number
    int big = -2147483648;
    for (int i: mass) if (i>big) big = i;

    // find all posible starts
    std::vector<int> posible_starts = {0};
    for (int i=0;i<mass.size()-1;i++){
        if ((mass[i]<=0)&&(mass[i+1]>0)) posible_starts.push_back(i+1);
    }

    // find all posible ends
    std::vector<int> posible_ends = {(int)mass.size()-1};
    for (int i=0;i<mass.size()-1;i++){
        if ((mass[i]>0)&&(mass[i+1]<=0)) posible_ends.push_back(i);
    }
    
    for (int i : posible_starts){
        for (int j : posible_ends){
            int bigS = summ(i,j); 
            if (bigS>big){
                big = bigS;
                coord[0] = i;
                coord[1] = j;
            }
        }
    }

    
    for (int i=0;i<mass.size();i++) if (mass[i]==big) {coord[0] = i; coord[1] = i;}
    std::cout << "the biggest sequens starts from : " << coord[0] << " and ends with : " << coord[1] << std::endl;
    system("pause");   
    return 0;
}