#include <iostream>

bool tiny[] = {true};
bool small[] = {true,true};
bool medium[] = {true,true,true};
bool large[] = {true,true,true,true};

int main() {
    std::cout << sizeof(tiny)/sizeof(tiny[0])<< std::endl;
    std::cout << sizeof(small)/sizeof(small[0]) << std::endl;
    std::cout << sizeof(medium)/sizeof(medium[0]) << std::endl;
    std::cout << sizeof(large)/sizeof(large[0]) << std::endl;
    return 0;
}
