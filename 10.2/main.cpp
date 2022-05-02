#include <iostream>

bool email_validation(const std::string& email){
    // divide email by 2 part and chek it separatly

    //firs part will be all characters before first '@'
    std::string firstPart = email.substr(0,email.find('@'));

    // first part can`t be larger than 64 or empty
    if ((firstPart.size()>64)||firstPart.empty()) return false;

    // can`t start or end with '.'
    if ((firstPart.front() == '.')||(firstPart.back()=='.')) return false;

    bool dotFlag = false;
    std::string corChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.!#$%&'*+-/=?^_`{|}~";
    for (char i : firstPart) {
        // forbidden  character check
        if (corChar.find(i) == std::string::npos) return false;

        //  can`t contain double dot
        if ((i == '.')&&(dotFlag)) return false;
        else if (i == '.') dotFlag = true;
        else dotFlag = false;
    }

    // second part is all what remained except '@'
    std::string secondPart = email.substr(firstPart.size()+1,email.size()-firstPart.size());

    // second part chek almost the same
    // except it can`t contain:  !#$%&'*+-/=?^_`{|}~
    // and max size is 63
    if ((secondPart.size()>63)||secondPart.empty()) return false;

    if ((secondPart.front() == '.')||(secondPart.back()=='.')) return false;
    dotFlag = false;
    corChar = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";
    for (char i : secondPart) {

        // forbidden  character check
        if (corChar.find(i) == std::string::npos) return false;
        if ((i == '.')&&(dotFlag)) return false;
        else if (i == '.') dotFlag = true;
        else dotFlag = false;

    }


    return true;
}


int main() {

    std::cout << "Please enter your email address: ";
    std::string emailStr;
    std::getline(std::cin,emailStr);

    std::cout << ((email_validation(emailStr))?"Yes":"No");

    return 0;
}
