#include <iostream>


#define vanCount 10
#define enter_pass(passMass) std::cin >> passMass[i]; 
#define count_overpass_van(vanCounter,passMass) if (passMass[i] > 20) vanCounter++;
#define count_underpass_van(vanCounter,passMass) if (passMass[i] < 20) vanCounter++;
#define count_pass(passCounter,passMass) passCounter += passMass[i]; 
#define thrue_van(command) for (int i=0;i<vanCount;i++){command}


int main(int argc, char** argv)
{
    int pMass[vanCount];
    thrue_van(enter_pass(pMass));
    
    int underV = 0;
    thrue_van(count_underpass_van(underV,pMass));
    std::cout << "Underpass vans: " << underV << std::endl;

    int overV = 0;
    thrue_van(count_overpass_van(overV,pMass));
    std::cout << "Overpass vans: " << overV << std::endl;

    int totalP = 0;
    thrue_van(count_pass(totalP,pMass));
    std::cout << "Total pass: " << totalP << std::endl;

    return 0;
}