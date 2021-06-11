#include <iostream>

int N = 0; // total people
int Ni[5]; // people per flour

int main() {
    std::cout << "Enter total amount of people living in this apartments: ";
    std::cin >> N;
    if (N<=0) {
        std::cerr << "total amount can`t be a negative number or be equal to zero";
        return 1;
    }

    int Ni_sum = 0;
    for (int i=0;i<5;i++){
        std::cout << "Enter number of people at " << i+1 << " floor : ";
        std::cin >> Ni[i];
        if (Ni[i]<0) {
            std::cerr << "you cant nave a negative number of people at " << i+1 << " floor";
            return 1;
        }
        Ni_sum += Ni[i];
    }

    float self_isolation_lvl = float(Ni_sum*100)/float(N);
    std::cout << "self isolation level is " << self_isolation_lvl << std::endl;
    return 0;
}
