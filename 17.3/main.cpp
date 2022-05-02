#include <iostream>

int f(int n,const int k =3){
    int ans = 0;
    if (n == 0) return 1;
    if (n <0) return 0;

    for (int i=1;i<=k;i++){
        ans += f(n-i,k);
    }
    
    return ans;
}


int main(int argc, char** argv){
    int n,k;
    std::cout << "enter n and k value (n k): ";
    std::cin >> n >> k;

    std::cout << f(n,k) << " - ways" << std::endl;

    return 0;
}