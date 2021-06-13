#include <iostream>
#include <vector>
#include <cstdlib>
char spaces[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
std::vector<std::vector<int>> p1_field;
std::vector<std::vector<int>> p2_field;


void draw_build_field(int player){
       system("clear");
       std::cout << "Player " << player << std::endl;
       std::cout << "  0 1 2 3 4 5 6 7 8 9 " << std::endl;
       for(int i=0;i<10;i++){
           std::cout << i << ' ';
           for(int j=0;j<10;j++){
               if ((player==1?p1_field[i][j]:p2_field[i][j])==0) std::cout << "\x1b[34m~\x1b[0m" << ' ';
               if ((player==1?p1_field[i][j]:p2_field[i][j])==1) std::cout << "\x1b[35m#\x1b[0m" << ' ';
           }
           std::cout << spaces;
           if (i<4) {
               for (int j = 0; j < 4 - i; j++) std::cout << "\x1b[35m#\x1b[0m";
               std::cout << " x" << i+1 << std::endl;
           }
           else std::cout << std::endl;
       }
   }

void draw_war_field(int player){
    system("clear");
    std::cout << "Player 1" << "           " << spaces << "Player 2" << std::endl;
    std::cout << "  0 1 2 3 4 5 6 7 8 9 " << spaces << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for(int i=0;i<10;i++){
        std::cout << i << ' ';
        for(int j=0;j<10;j++){
            if (p1_field[i][j]==0) std::cout << "\x1b[34m~\x1b[0m" << ' ';
            if (p1_field[i][j]==1) std::cout << (player==1?"\x1b[35m#\x1b[0m":"\x1b[34m~\x1b[0m") << ' ';
            if (p1_field[i][j]==2) std::cout << "\x1b[31m@\x1b[0m" << ' ';
        }
        std::cout << spaces;
        std::cout << i << ' ';
        for(int j=0;j<10;j++){
            if (p2_field[i][j]==0) std::cout << "\x1b[34m~\x1b[0m" << ' ';
            if (p2_field[i][j]==1) std::cout << (player==2?"\x1b[35m#\x1b[0m":"\x1b[34m~\x1b[0m") << ' ';
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

    //player1 set his ship
    int  ships = 0;
    int x,y;
    while (ships<20) {
    draw_build_field(1);
    if (ships<4){
        std::cout << "Please enter ship coordinates (x,y): ";
        x = parse_input()[0];
        y = parse_input()[1];
        place_ship(p1_field,1,x,y, false);
        ships += 1;
    }
    }

    // player2 set his ship

    //while (!build_done) {
    //}

    //game loop
    bool quit = false;
    //while (!quit){

    //}
    return 0;
}
