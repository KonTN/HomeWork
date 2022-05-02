#include <iostream>
#include <fstream>
#include <ctime>


int main(int argc,char** argv){

    int height,width;
    std::cout << "Enter picture size (height width): ";
    std::cin >> height >> width;

    std::ofstream fStream;
    fStream.open("pic.txt");
    if (!fStream.is_open()){
        std::cout << "Error: can`t open file 'pic.txt'";
        return 1;
    }

    std::srand(std::time(nullptr)); // to get diffrent random sead

    for (int i = 0;i <height;i++){
        for(int j=0;j<width;j++){
            fStream << rand()%2;
        }
        fStream << std::endl;
    }

    fStream.close();
    return 0;
}