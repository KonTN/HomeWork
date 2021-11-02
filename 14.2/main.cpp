#include <iostream>
#include <vector>
#include <set>


std::vector<int> mass = {2,7,11,15};
short resolt = 13;

int main(){

    std::set<int> lover;
    std::set<int> hieghter;
    for (int i: mass){
        if (i>(int)(resolt/2)) hieghter.insert(i);
        else lover.insert(i);
    }

    for (int i : lover){
        for (int j : hieghter){
            int summ = i+j;
            if (summ==resolt) {std::cout << i << " + " << j << " = " << resolt << std::endl; system("pause"); return 0;}
            if (summ>resolt) break;
        }
    }
    system("pause");
    return 0;
}