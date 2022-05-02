#include <iostream>
#include <fstream>




int main(int argc, char** argv){


    std::cout << "Enter file path: ";
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path,std::ios::binary); 
    if (!file.is_open()){
        std::cout << "Error can`t open file \""<< path << "\"" << std::endl;
        return 1;
    }
    

    if(path.substr(path.find('.')+1,3)== "png"){
        char buff[4];
        file >> buff;
        if ((buff[0] == -119)&&(buff[1] == 'P')&&(buff[2] == 'N')&&(buff[3] == 'G')){
            std::cout << "PNG file" << std::endl;
            file.close();
            return 0;
        }
    }



    std::cout << "not PNG file" << std::endl;
    file.close();
    return 0;
}