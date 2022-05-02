#include <iostream>


void swap(int* a, int* b){
    int buf = *a;
    *a = *b;
    *b = buf;
}


int main(int argc, char** argv){ 

    int a = 20;

    int b = 10; 

    swap (&a,&b);

    std::cout << a << ' ' << b;



    return 0;
}
