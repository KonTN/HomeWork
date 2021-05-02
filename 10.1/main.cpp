#include <iostream>
#define  EnLettersCount 26;

void encrypt_caesar(std::string &uncryptStr, int shift){
    shift %= EnLettersCount;
    for (char & i : uncryptStr){
        if ((i >= 'A')&&(i<='Z')){
            if (i+shift>'Z'){
                i += shift - EnLettersCount;
            } else if (i+shift<'A'){
                i += shift +EnLettersCount;
            } else {
                i += shift;
            }
        }
        else if ((i>= 'a')&&(i<='z')) {
            if (i+shift>'z'){
                i += shift - 26;
            } else if (i+shift<'a'){
                i += shift +26;
            } else {
                i += shift;
            }
        }
    }
}
void decrypt_caesar(std::string &cryptStr, int shift) {
    encrypt_caesar(cryptStr,-shift);
}


std::string parsedStr;

int main() {
    std::cout << "Enter your str: ";
    std::getline(std::cin, parsedStr);
    std::cout << "Enter shift: ";
    int shift;
    std::cin >> shift;
    encrypt_caesar(parsedStr,shift);
    std::cout << "Crypted str: " << parsedStr << std::endl;
    decrypt_caesar(parsedStr,shift);
    std::cout << "Decrypted str: " << parsedStr << std::endl;
    return 0;
}
