#include <iostream>
#include <vector>

std::vector<int> base;

int main() {
    int inp;
    int ofsend = 0;
    std::cin >> inp;
    while (inp != -1){
        base.push_back(inp);
        for (int i : base) std::cout << i << ' ';

        if (base.size()>20){
            ofsend ++;
            if (base.size()==base.capacity()){
               for (int i = ofsend;i<base.size();i++) base[i-ofsend] = base[i];
               base.resize(20);
               ofsend = 0;
            }
        }
        std::cin >> inp;

    }
    for (int i = ofsend;i<base.size();i++) base[i-ofsend] = base[i];
    base.resize(20);
    for (int i : base) std::cout << i << ' ';
}
