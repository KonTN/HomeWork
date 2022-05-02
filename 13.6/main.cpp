#include <iostream>

float mat[4][4],vec[4];

int main() {

    std::cout << "input matrix: " << std::endl;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            std::cin >> mat[i][j];
        }
    }

    std::cout << "input vector: " << std::endl;
    for (int i=0;i<4;i++) std::cin >> vec[i];

    float res[4]; // ressoult vector
    for (int i=0;i<4;i++){
        res[i] = mat[i][0]*vec[0]+mat[i][1]*vec[1]+mat[i][2]*vec[2]+mat[i][3]*vec[3];
    }

    // ressoult vector output
    for (int i=0;i<4;i++){
        std::cout << res[i]<< ' ';
    }
    std::cout << std::endl;

    system("pause");    
    return 0;
}