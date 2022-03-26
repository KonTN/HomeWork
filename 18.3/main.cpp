#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void parseStr(std::string str, std::string& name, int& max, int& sum){
    
    std::stringstream s;
    std::string fName, sName;
    s << str;
    int value,dummy;
    s >> fName >> sName >> value >> dummy;

    if (value > max) {
        name = fName+" "+sName; // glue first name and second name in one str
        max = value;
    }
    sum += value; 
}

int main(int argc,char** argv){

    // open file
    std::ifstream file;
    file.open("table.txt");     

    int max = 0; // max salary
    int sum = 0; // total salary
    std::string maxName;
   
    // read file str by str
    std::string buff;
    while (getline(file,buff)){
        parseStr(buff,maxName,max,sum);
    }

    std::cout << maxName << " has the highest salary ( "<< max << " )" << std::endl;
    std::cout << "Total salary: " << sum << std::endl;
    file.close();
    return 0;
}