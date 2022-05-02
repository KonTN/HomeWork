#include <iostream>


bool pup_pup(bool pup[][12],int x,int y){
    if ((x<12)&(y<12)) {
        if (pup[x][y]) {std::cout << "Pup!" << std::endl; pup[x][y] = false;}
        return true;
    }
    std::cout << "Error, x or y cood > pup size" << std::endl;
    return false;
}

void rectangle_pup(bool pup[][12], int x1, int y1, int x2, int y2){
    for (int i=x1;i<x2;i++){
        for (int j=y1;j<y2;j++) {
            if(!pup_pup(pup,i,j)) break;
        }
    }
}

void print_pup(bool pup[][12]){
    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            std::cout << ((pup[i][j]==true)?'o':'x') << ' ';
        }
        std::cout << std::endl;
    }
}


void fill_pup(bool pup[][12]){
    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            pup[i][j] = true;
            
        }
    }
}


bool pup_chek(bool pup[][12]) {
    for (int i=0;i<12;i++){
        for (int j=0;j<12;j++){
            if (pup[i][j]==true) return true;       
        }
    }
    return false;
}


int main(){
    bool pup[12][12];
    fill_pup(pup);
    while (pup_chek(pup)){
        system("cls");
        print_pup(pup);
        std::cout << "Input your pup rectangle (x1 y1 x2 y2): ";
        int x1,y1,x2,y2;
        std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2;
        rectangle_pup(pup,x1,y1,x2,y2);       
    }

    system("pause");
    return 0;
}