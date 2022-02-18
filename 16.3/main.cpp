#include <iostream>

bool substr(char* a, char* b){
    int j=0;
    for (int i=0;a[i] != '\0'; i++){
        if (a[i] == b[j]){
            if (b[j+1]!='\0'){
                j++;
            }
            else return true;
        }
        else j=0;
    }  
    return false;
}


int main(int argc, char** argv){
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";


    std::cout << substr(a,b) << ' ' << substr(a,c) << std::endl;
    return 0;
}
