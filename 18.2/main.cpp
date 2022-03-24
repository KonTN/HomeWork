#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char** argv){
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path); 
    if (!file.is_open()){
        std::cout << "Error can`t open file \""<< path << "\"" << std::endl;
        return 1;
    }

    std::string buff;
    while (getline(file,buff)){
        std::cout << buff << std::endl;
    }

    return 0;
}