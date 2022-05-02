#include <iostream>
#include <vector>



int vip[2][8];  //vip tableware
                 // 2 seats ↴
                 //     personal set with extra dessert accessories:
                 //         1 spoon
                 //         2 knife
                 //           ....
                 //         5 dessert spoon
                 //         6 dessert plate
                 //           ....
                 //         8 chair
int regularMortals[2][5][6]; // regular persons tableware 
                              // 2 row ↴   
                              //    5 seats ↴
                              //        personal set

int main() {
    // gives all vip persons tableware 
    for (int i=0;i<2;i++){
        for (int j=0;j<8;j++) vip[i][j] = 1;
    }
    // gives all martals table ware
    for (int i=0;i<2;i++){
        for (int j=0;j<5;j++) {
            for (int k=0;k<6;k++) regularMortals[i][j][k] = 1;
        }
    }

    //extra chair for yung mom
    regularMortals[1][5][8] ++;
    //stolen spoon
    regularMortals[2][3][1] --;
    // vip kindness
    vip[1][5] --;
    regularMortals[2][3][1] ++;
    vip[1][6] --;

    return 0;
}