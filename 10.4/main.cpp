#include <iostream>

std::string add_zero_back(std::string less, int zeroCount) {
    std::string cStr;
    cStr.append(less);
    for (int i =0; i<zeroCount;i++){
        cStr.append("0");
    }
    return cStr;
}

std::string add_zero_front(std::string less, int zeroCount) {
    std::string cStr;
    if (less.front() == '-') {
        less.erase(0,1);
        cStr.append("-");
    }
    for (int i =0; i<zeroCount;i++){
        cStr.append("0");
    }
    cStr.append(less);
    return cStr;
}

void equalize_values(std::string &first,std::string &second) {
    if (first.find('.')<second.find('.')){
        first = add_zero_front(first,int(second.find('.')-first.find('.')));
    }
    else {
        second = add_zero_front(second,int(first.find('.')-second.find('.')));
    }
    if (first.size()<second.size()){
        first = add_zero_back(first,int(second.size()-first.size()));
    }
    else {
        second = add_zero_back(second,int(first.size()-second.size()));
    }
}

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

int minus_zero_delete(std::string &num){
    if (num.front() == '-') {
        for (const char i : num) {
            if (!((i =='0')||(i=='.')||(i=='-'))) return 1;
        }
        num.front() = '0';
    }
    return 0;
}

int main() {
    std::cout << "This program compare 2 numbers written in the next line\n";
    std::string firstNum,secondNum;
    std::cout << "Enter your line: ";
    std::cin >> firstNum >> secondNum;

    // make copy of values so we can modify them without any influences to result output;
    std::string firstNumC = firstNum;
    std::string secondNumC = secondNum;

    // add dot to the value if value don`t contain it;
    if (firstNumC.find('.') == std::string::npos) firstNumC.append(".");
    if (secondNumC.find('.') == std::string::npos) secondNumC.append(".");

    // swap first and second num if both of they negative (to our comparation work right)
    if ((firstNumC.front() == '-')&&(secondNumC.front() == '-')) {
        std::string buff;
        buff = firstNum;
        firstNum = secondNum;
        secondNum = buff;
    }
    //delete minus if it zero
    minus_zero_delete(firstNumC);
    minus_zero_delete(secondNumC);
    // only way we to compare this values is that both of this values are float numbers
    if (float_validation(firstNumC)&&float_validation(secondNumC)) {
        // equlize characters quantity
        equalize_values(firstNumC,secondNumC);
        // ASCII table contains characters in gentle to us order
        // so, all we need is just compare them using ASCII number
        for (int i = 0; i<firstNumC.size();i++){
            if (firstNumC[i]<secondNumC[i]){
                std::cout << firstNum << " < " << secondNum;
                return 0;
            }
            else if (secondNumC[i]<firstNumC[i]) {
                std::cout << firstNum << " > " << secondNum;
                return 0;
            }
        }
        // if we passed all the way through both values and did`t find bigger or less digit
        // it meant that values equal to each other
        std::cout << firstNum << " = " << secondNum;
        return 0;
    }
    else {
        std::cout << "Error : can`t compare " << firstNum << " and " << secondNum;
        return -1;
    }
}
