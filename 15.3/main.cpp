#include <iostream>
#include <sstream>


int main(){
    std::stringstream buff; 
    std::string nymeracy;

    std::cin >> nymeracy;
    buff << nymeracy;

    double num1,num2;
    char operation;

    buff >> num1 >> operation >> num2;

    switch (operation)
    {
    case '+':
        std::cout << num1 << " + " << num2 << " = " << num1+num2 << std::endl;
        break;
    case '-':
        std::cout << num1 << " - " << num2 << " = " << num1-num2 << std::endl;
        break;
    case '*':
        std::cout << num1 << " * "  << num2 << " = " << num1*num2 << std::endl;
        break;
    case '/':
        if (num2 != 0) std::cout << num1 << " / " << num2 << " = "  << num1/num2 << std::endl;
        else std::cout << "zero division error!" << std::endl;
        break;
    default:
        std::cout << "wrong operation error" << std::endl;
        break;
    };
    


    return 0;
}