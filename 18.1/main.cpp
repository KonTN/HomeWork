#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char** argv){

    std::ifstream book;
    book.open("book.txt"); // book text: The Second Richard Deming Mystery MEGAPACK Classic Mystery Stories
    if (!book.is_open()){
        std::cout << "Error can`t open file" << std::endl;
        return 1;
    }
    
    
    std::string word;
    std::cout << "enter word: ";
    std::cin >> word;

    int wordCoincident = 0;
    std::string buff; // file reading buffer
    while (book >> buff){
        if (buff == word) wordCoincident ++;
    }

    std::cout << wordCoincident << std::endl;

    book.close();
    return 0;
}