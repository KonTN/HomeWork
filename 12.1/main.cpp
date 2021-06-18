#include <iostream>
#include <vector>

int main() {

    // get vector size
    int vec_cop;
    std::cout << "Enter vector capacity: ";
    std::cin >> vec_cop;
    if (vec_cop<=0) {std::cerr << "vector capacity must be > 0"; return -1;}

    // get vector values
    std::vector<int> num_vec;
    int buff;
    for (int i = 0; i<vec_cop;i++){
        std::cout << "  enter vector value "<< '(' << i+1 <<" of " << vec_cop <<"): ";
        std::cin >> buff;
        num_vec.push_back(buff);
    }

    // erasing value
    int erase_val;
    std::cout << "Enter erase value: ";
    std::cin >> erase_val;
    int base = 0;
    for (int i;i<num_vec.size();i++){
        if (num_vec[i]!=erase_val) {
            num_vec[base] = num_vec[i];
            base++;
        };
    }
    num_vec.resize(base);

    // cout vector
    for (int i : num_vec){
        std::cout << i << ' ';
    }


    return 0;
}
