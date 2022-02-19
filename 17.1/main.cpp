#include <iostream>
#include <vector>



void swapvec(std::vector<int> &vec, int mass[]){
    for (int i=0;i<vec.size();i++){
        int buff = vec[i];
        vec[i] = mass[i];
        mass[i] = buff;
    }        

}



int main(int argc, char** argv){


    std::vector<int> a = {1,2,3,4};
    int b[] = {2,4,6,8};
    
    swapvec(a,b);
    for (int num : a){
        std::cout << num << ' ';
    }
    std::cout << std::endl;
    
    for (int num : b){
        std::cout << num << ' ';    
    }
    std::cout << std::endl;

    return 0;
}
