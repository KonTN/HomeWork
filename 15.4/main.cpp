#include <iostream>
#include <vector>


int main(){
    enum notes{
        C = 1,
        D,
        E,
        F,
        G,
        A,
        B
    };
    std::vector<std::string> melodies;

    for (int i = 0;i < 12; i++){
        std::string buff;
        std::cin >> buff;
        melodies.push_back(buff);
    }

    for (std::string str : melodies){
        for (char i : str){
            switch (i-'0')
            {
            case C:
                std::cout << " C ";
                break;
            case D:
                std::cout << " D ";
                break;
            case E:
                std::cout << " E ";
                break;
            case F:
                std::cout << " F ";
                break;
            case G:
                std::cout << " G ";
                break;
            case A:
                std::cout << " A ";
                break;
            case B:
                std::cout << " B ";
                break;
            }
        }
        std::cout << std::endl;
    }
   
    return 0;
}