#include <iostream>
#include <string>

#define delta 0.001

bool is_bigger(float bigger, float lower){
    return (bigger-delta)>lower;
}


int main(){
    std::string speed = "0";

    float buff;
    do {
        std::cin >> buff;
        speed = std::to_string(stof(speed)+buff);
        std::cout << speed << std::endl;
    } while (is_bigger(stof(speed),0));
}