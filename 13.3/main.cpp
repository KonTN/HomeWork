#include <iostream>

int num[5][5];

int main() {

    for (int i=0;i<5;i+=2) {
        for (int j=0;j<5;j++) {
            num[i][j] = i*5+j;
        }
        for (int j=0;j<5;j++) {
            num[i+1][4-j] = (i+1)*5+j;
                
        }
    }

    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            std::cout << num[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}