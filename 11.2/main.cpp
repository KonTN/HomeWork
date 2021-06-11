#include <iostream>
int fit_club[2];
int store[1];
int cottage[3];
int apartment[15];
int skyscraper[60];
int main() {
    float flours_mean = sizeof(fit_club)+sizeof(store)+sizeof(cottage)+sizeof(apartment)+sizeof(skyscraper);
    flours_mean /=5; // 5 type of buildings
    flours_mean /= sizeof(fit_club[0]) ; // numbers of byte -> numbers of flour
    std::cout << "flours mean in this area is : " << flours_mean << std::endl;
    return 0;
}
