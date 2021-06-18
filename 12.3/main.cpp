#include <iostream>
#include <vector>

std::vector<int> base;

int main() {
    int inp;
    int tail = 0;
    std::cin >> inp;
    while (inp != -1){

        if (base.size()>=20) {
            base[tail] = inp;
            tail ++;
            if (tail >=20) tail = 0;
        }
        else base.push_back(inp);
        for (int i : base) std::cout << i << ' ';
        std::cin >> inp;
    }
    for (int i=0;i<base.size();i++){
        base[i] = base[(i+tail>20)?i+tail-20:i+tail];
    }
    for (int i : base) std::cout << i << ' ';
}
