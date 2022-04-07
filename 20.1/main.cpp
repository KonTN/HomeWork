#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

struct payment{
    std::string names = "empte name";
    std::string date = "00.00.00";
    int salary = 0;
};

void parse_string(const std::string& str,payment& data){
    std::stringstream strStream;
    strStream << str;
    std::string lastName;
    strStream >> data.names >> lastName >> data.date >> data.salary;
    data.names += " " + lastName;
}


int main(int argc, char** argv){

    std::cout << "command: list - show all payments, add - add new payment" << std::endl;
    std::cout << "Enter command: ";
    std::string command;
    std::cin >> command;

    if ((command != "list")&&(command != "add")){
        std::cout << "Error: wrong command";
        return 0;
    }

    // show all payments
    if (command == "list"){
        
        std::ifstream inPayFile;
        inPayFile.open("data.txt");
        
        
        std::vector<payment> payVec;
        std::string buff;
        payment dummy;
        for  (int i=0;getline(inPayFile,buff);i++){
            payVec.push_back(dummy);
            parse_string(buff,payVec[i]);
        }
        for (payment i : payVec){
            std::cout << i.names << " " << i.salary << " " << i.date << std::endl;
        }
        inPayFile.close();
    }

    //add new payment
    if (command == "add"){
        
        // get data input
        payment newPay;

        std::cout << "Please enter your data" << std::endl;
        std::cout << "  First_Name Last_Name :";
        std::string lastName;
        std::cin >> newPay.names;
        std::cin >> lastName;
        newPay.names += " " + lastName ;
        std::cout << "  Date :";
        std::cin >> newPay.date;
        std::cout << "  Salary :";
        std::cin >> newPay.salary;

        //verify names 
        if (newPay.names.empty()) {            
            std::cout << "Error: empty First_Name Last_Name";
            return 1;
        }

        //verify salary 
        if (!newPay.salary) {            
            std::cout << "Error: null salary";
            return 1;
        }
        
        // verify date
        int year = std::stoi(newPay.date.substr(6,4));
        int month = std::stoi(newPay.date.substr(3,2));
        int day = std::stoi(newPay.date.substr(0,2));
        
        if (year <= 0) {
            std::cout << "Error: wrong date";
            return 1;
        }
        
        if ((month <= 0)||(month>12)) {
            std::cout << "Error: wrong date";
            return 1;
        }
        
        const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        
        if ((day <= 0)||(day>daysInMonth[month-1])) {
            std::cout << "Error: wrong date";
            return 1;
        }
        
        // file write
        std::ofstream outPayFile;
        outPayFile.open("data.txt",std::fstream::app);
        outPayFile << newPay.names << " " << newPay.salary << " " << newPay.date << std::endl;
        outPayFile.close();
   }

    return 0;
}