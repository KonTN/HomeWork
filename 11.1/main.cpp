#include <iostream>

bool tiny[] = {true};
bool small[] = {true,true};
bool medium[] = {true,true,true};
bool large[] = {true,true,true,true};

int main() {
    // righter version would be sizeof(mass)/sizeof(elem), but bool variable take only one bit of memory
    // so we not need use dividing to get right result
    std::cout << sizeof(tiny)<< std::endl;
    std::cout << sizeof(small) << std::endl;
    std::cout << sizeof(medium) << std::endl;
    std::cout << sizeof(large) << std::endl;
    return 0;
}
