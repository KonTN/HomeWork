#include <iostream>


int f(int n){

    if (n == 0) return 1;
    if (n<0) return 0;
    return f(n-1)+f(n-2)+f(n-3);
}

int main(int argc, char** argv){
    int n;
    std::cout << "Enter n value: ";
    std::cin >> n;

    std::cout << f(n) << " - ways" << std::endl;
    return 0;
}