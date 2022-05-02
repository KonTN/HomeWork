#include <iostream>
#include <fstream>





int main(int argc,char** argv){

    std::ifstream fishTypeFile;
    fishTypeFile.open("river.txt");

    std::ofstream FishBucketFile;
    FishBucketFile.open("basket.txt",std::fstream::app);

    std::cout << "Please enter fish type: ";
    std::string fishType;
    std::cin >> fishType;

    int counter = 0;
    
    std::string buff;
    while (std::getline(fishTypeFile,buff)){
        if (buff == fishType){
            FishBucketFile << buff << std::endl;
            counter ++;
        }
    }

    std::cout << "Due this fishing session " << counter << " fish were caught!" << std::endl;
    
    fishTypeFile.close();
    FishBucketFile.close();
    return 0;
}