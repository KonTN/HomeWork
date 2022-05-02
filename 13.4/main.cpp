#include <iostream>

bool mat_comp(double mat1[][4], double mat2[][4]){
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (mat1[i][j] != mat2[i][j]) return false;
        }
    }
    return true;
}

int main() {
    double mat1[4][4];
    double mat2[4][4];
    
    std::cout << "mat1: " << std::endl;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            std::cin >> mat1[i][j];
        }   
    }

    std::cout << "mat2: " << std::endl;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            std::cin >> mat2[i][j];
        }
    }

    std::cout << "matrix is " << (mat_comp(mat1,mat2)?" ":"not ") << "equal!" << std::endl;
    system("pause");

    return 0;
}