#include <iostream>

bool earth[5][5][10];

int main(){
    std::cout << "please enter your lanscape: ";
    std::cout << "(h h h h h\n                             h h h h h\n                             h h h h h\n                             h h h h h\n                             h h h h h)\n";
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            int buff;
            std::cin >> buff;
            if ((buff <0)||(buff > 9)) {std::cout << "Landscape out of range"; return -1;}
            for (int k=0;k<buff;k++) earth[i][j][k] = true;
        }
    }
    std::cout << "enter layer: ";
    int layer; std::cin >> layer;
    if ((layer <0)||(layer > 9)) {std::cout << "Layer out of range"; return -1;}
    
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            std::cout << earth[i][j][layer] << ' ';
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}