#include <iostream>
#include <vector>

std::vector<float> price = {10.1f, 10.2f, .99f, 10.f};
std::vector<int> purchase = {0,0,1,3,2};

int main() {
    float sum = 0;
    for (int i: purchase){
        if ((i>=0)&&(i<=price.size())) sum+= price[i];
        else {
            std::cerr << "vector out of range";
            return -1;
        }
    }
    std::cout << "Sum : " << sum;
    return 0;
}
