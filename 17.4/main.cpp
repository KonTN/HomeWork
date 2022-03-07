#include <iostream>

void f(long long n, int& ans){
    
    if (n%2==0) ans+=1; 
    if (n<10) return ;
    f(n/10,ans);
}



int main(int argc, char** argv){

    int ans = 0;
    f(0, ans);
    std::cout << ans << std::endl;

    return 0;
}