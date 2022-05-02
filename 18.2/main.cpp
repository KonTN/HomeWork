#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char** argv){
    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path, std::ios::binary); 
    if (!file.is_open()){
        std::cout << "Error can`t open file \""<< path << "\"" << std::endl;
        return 1;
    }

    char buff[16];
    while (!file.eof()){
        file.read(buff, sizeof(buff) - 1);
        buff[file.gcount()] = 0;
        std::cout << buff ;
    }

    file.close();
    return 0;
}