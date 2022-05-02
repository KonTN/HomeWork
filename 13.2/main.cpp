#include <iostream>
#include <vector>

char field[3][3];
bool game_finished = false;

void draw_field(){
    std::cout << field[0][0] << " | " << field[1][0] << " | " << field[2][0] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << field[0][1] << " | " << field[1][1] << " | " << field[2][1] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << field[0][2] << " | " << field[1][2] << " | " << field[2][2] << std::endl;
};

bool try_win(int x,int y,bool turn){
    field[x][y] = (turn?'X':'0');
    for (int i=0;i<3;i++){
        if ((field[i][0]==field[i][1])&&(field[i][0]==field[i][2])
                &&(field[i][0]!=' ')) return 1;
        if ((field[0][i]==field[1][i])&&(field[0][i]==field[2][i])
                &&(field[0][i]!=' ')) return 1;
    }
    return 0;
};

int main() {
    // fill field with ' '
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++) field[i][j] = ' ';
    }

    // game loop
    for (int turn = 0;turn < 9; turn ++){
        system("cls"); //clear console buff
        draw_field(); // draw battle field
        
        // input coord
        std::cout << turn%2+1 << " player turn: " << std::endl;
        int x,y;
        std::cout << "x: "; 
        std::cin >> x; 
        std::cout << "y: "; 
        std::cin >> y; 
        std::cout << std::endl;


        // coord check
        if (((x>2)||(y>2))||(field[x][y] != ' ')) {std::cout << "Coord error" << std::endl; system("pause");  return -1;}  

        if (try_win(x,y,turn%2)) {
            std::cout << "Congratulations!!! " << turn%2+1 << " player win";
            system("pause");
            return 0; 
        }
    }
    std::cout << "fair drawn game!" << std::endl;
    system("pause");
    return 0;
}