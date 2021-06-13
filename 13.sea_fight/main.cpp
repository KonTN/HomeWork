#include <iostream>
#include <vector>
#include <cstdlib>
char spaces[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
std::vector<std::vector<int>> p1_field;
std::vector<std::vector<int>> p2_field;

void draw_field(){
    system("clear");
    std::cout << "Player 1" << "           " << spaces << "Player 2" << std::endl;
    std::cout << "  0 1 2 3 4 5 6 7 8 9 " << spaces << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for(int i=0;i<10;i++){
        std::cout << i << ' ';
        for(int j=0;j<10;j++){
            if (p1_field[i][j]==0) std::cout << "\x1b[34m~\x1b[0m" << ' ';
            if (p1_field[i][j]==1) std::cout << "\x1b[35m#\x1b[0m" << ' ';
            if (p1_field[i][j]==2) std::cout << "\x1b[31m@\x1b[0m" << ' ';
        }
        std::cout << spaces;
        std::cout << i << ' ';
        for(int j=0;j<10;j++){
            if (p2_field[i][j]==0) std::cout << "\x1b[34m~\x1b[0m" << ' ';
            if (p2_field[i][j]==1) std::cout << "\x1b[35m#\x1b[0m" << ' ';
            if (p2_field[i][j]==2) std::cout << "\x1b[31m@\x1b[0m" << ' ';
        }
        std::cout << std::endl;
    }
}
int place_ship(std::vector<std::vector<int>> &field,int size, int x, int y,bool orientation){
    if ((y+size*orientation<=field.size())&&(x+size*!orientation<=field[0].size())){
        for (int i=0;i<size;i++){
            field[x+i*!orientation][y+i*orientation] = 1;
        }
        return 0;
    }
    return -1;
}


int main() {
    // filling in the field
    std::vector<int> buf;
    buf.resize(10);
    for (int i=0;i<10;i++){
        p1_field.push_back(buf);
        p2_field.push_back(buf);
    }
    //player1 first turn
    draw_field();
    place_ship(p1_field,4,0,0,true);



    draw_field();
    return 0;
}
