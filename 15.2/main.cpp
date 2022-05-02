#include <iostream>
#include <sstream>



int main(){
    int integerPart, fractionalPart;
    std::cout << "please enter integer and fractional part of number(xx yy): ";
    std::cin >> integerPart >> fractionalPart;
    std::stringstream buff;
    buff << std::to_string(integerPart) << '.' << std::to_string(fractionalPart);
    double num = stod(buff.str());
    std::cout << num;
    return 0;
}