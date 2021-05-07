#include <iostream>

bool float_validation(std::string num){
    bool pointFlag = false, numFlag = false;
    do {
        if ((num.back()>='0')&&(num.back()<='9')){
            numFlag = true;
        } else if((num.back() == '.')&&(!pointFlag)){
            pointFlag = true;
        } else if ((num.back() == '-')&&(num.front() == num.back())){

        } else {
            return false;
        }
        num.pop_back();
    }while(!num.empty());
    return numFlag;
}

void leader_zero_delete(std::string &str){
    bool minusFlag = false;
    for (char i : str){
        if (str.front()=='0') {
            str.erase(0,1);
        }
        else if (str.front() == '-'){
            str.erase(0,1);
            minusFlag = true;
        }
    }
    if (minusFlag) str.insert(0,"-");
    std::cout << str << std::endl;
}

int main() {
    std::string firstNum,secondNum;
    std::cout << "Enter your line: ";
    std::cin >> firstNum >> secondNum;
    if (float_validation(firstNum)&&float_validation(firstNum)) {
        leader_zero_delete(firstNum);
        leader_zero_delete(secondNum);
        int lowSize =  (firstNum.size()<secondNum.size())?(int)firstNum.size():(int)secondNum.size();
        for (int i=0;i<lowSize;i++){
            if (firstNum[i]>secondNum[i]){
                std::cout << firstNum << " > "  << secondNum;
                return 0;
            }
            else if (firstNum[i]<secondNum[i]) {
                std::cout << secondNum << " > " << firstNum;
                return 0;
            }
        }

    }
    else {
        std::cout << "Error : can`t compare " << firstNum << " and " << secondNum;
        return -1;
    }
    std::cout << firstNum << " = "  << secondNum;
    return 0;
}
