#include <iostream>
# include <vector>

short coord[2];

bool positivity_test(std::vector<int> mass){
    for (int i : mass) if (i>0) return true;
    return false;
}


int main(){
// исходный массив 
std::vector<int> mass = {-2,1,-3,4,-1,2,1,-5,4};
std::vector<int> massN = {-2,-1,-3,-4,-1,-2,-1,-5,-4};

// should start and end with positive number
// cant start or end with negativiti sequence (like: 1 -1 -1 or 5 -4 -7)


// check that positivity number exist 
        // if not the bigger one would be the clothest to 0 number;
    

// find first positivity nimber

    std::cout << positivity_test(mass) << ' ' << positivity_test(massN);
    system("pause");
    return 0;
}