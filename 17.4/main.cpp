#include <iostream>

void f(long long n, int& ans){
   
    if (n==0) return ;
    if (n%2==0) ans+=1; 
    f(n/10,ans);
}



int main(int argc, char** argv){

    int ans = 0;
    f(9223372036854775806, ans);
    std::cout << ans << std::endl;

    return 0;
}