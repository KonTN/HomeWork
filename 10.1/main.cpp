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




int main() {

    // get str from cin
    std::cout << "Enter your str: ";
    std::string parsedStr;
    std::getline(std::cin, parsedStr);

    // get shift from cin
    std::cout << "Enter shift: ";
    int shift;
    std::cin >> shift;

    // crypting
    encrypt_caesar(parsedStr,shift);
    std::cout << "Crypted str: " << parsedStr << std::endl;

    // decrypting
    decrypt_caesar(parsedStr,shift);
    std::cout << "Decrypted str: " << parsedStr << std::endl;

    return 0;
}
