#include <iostream>
float mat[4][4];

int main(){
    // input matrix
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            std::cin >> mat[i][j];
            if (i!=j) mat[i][j] = 0;
        }
    }

    // output dio matrix
    std::cout << std::endl;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}