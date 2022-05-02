#include <iostream>


void rotate(int mass[],int size){
    for (int i=0;i<=size/2;i++){
        int buff = mass[i];
        mass[i]= mass[size-i];
        mass[size-i] = buff;
    }
}

int main(int argc, char** argv){

   int  val[10] = {0,1,2,3,4,5,6,7,8,9};

    rotate(val,9);

    for (const auto i : val){
        std::cout << i << ' ';
    }
    std::cout << std::endl;


    return 0;
}
