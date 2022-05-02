#include <iostream>
#include <sstream>
int str_to_int(std::string str){
    int num = 0;
    if (!str.empty()){
        for (char i:str){
            if ((i == '0')&&(str.front()==i)&&(str.size()>1)) return -1;  // leader '0' check
            if ((i<='9')&&(i>='0')) num = num*10+(i-'0');
            else {
                //std::cout << str << " is not positive integer number"<< std::endl;
                return -1;
            }
        }
    }
    else {
        //std::cout << "string is empty"<< std::endl;
        return -1;
    }
    return num;

}

bool ip_validation(const std::string &ip){
    int counter = 0;
    std::stringstream ipStream;
    ipStream << ip;
    std::string num;
    while (std::getline(ipStream,num,'.')){
        if ((str_to_int(num)>255)||(str_to_int(num)<0)) return false;
        counter ++;
    }
    if (counter!=4) return false; // more or less then 4 number check
    if (ip.back() == '.') return false; // last '.' check
    return true;
}



int main() {
    std::cout << "Please enter your ip address: ";
    std::string ipStr;
    std::getline(std::cin,ipStr);
    std::cout << ((ip_validation(ipStr))?"Yes":"No");
    return 0;
}
