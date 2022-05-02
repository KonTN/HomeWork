#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv){
     //open file 
    std::ofstream fileStream;
    fileStream.open("data.txt",std::fstream::app);
   
    bool quit = false;
    while (!quit){

        // get data input
        std::string names,date;    
        int salary;

        std::cout << "Please enter your data" << std::endl;
        std::cout << "  First_Name Last_Name :";
        std::getline(std::cin,names);
        std::cout << "  Date :";
        std::cin >> date;
        std::cout << "  Salary :";
        std::cin >> salary;

        //verify names 
        if (names.empty()) {            
            std::cout << "Error: empty First_Name Last_Name";
            return 1;
        }

        //verify salary 
        if (!salary) {            
            std::cout << "Error: null salary";
            return 1;
        }
        
        // verify date
        int year = std::stoi(date.substr(6,4));
        int month = std::stoi(date.substr(3,2));
        int day = std::stoi(date.substr(0,2));
        
        if (year <= 0) {
            std::cout << "Error: wrong date";
            return 1;
        }
        
        if ((month <= 0)||(month>12)) {
            std::cout << "Error: wrong date";
            return 1;
        }
        
        const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        if ((day <= 0)||(day>daysInMonth[month+1])) {
            std::cout << "Error: wrong date";
            return 1;
        }
        
        // file write
        fileStream << names << " " << salary << " " << date << std::endl;

        char buff;
        std::cout << "Enter 'q' to quit: ";
        std::cin >> buff;
        if (buff == 'q') quit = true;
    }

    fileStream.close();   
    return 0;
}