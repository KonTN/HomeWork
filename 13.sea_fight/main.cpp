# include <iostream>
#include <string>
// glabal wars
char p1_field[10][10]; 
char p2_field[10][10];
std::string spaces = "                    ";
short ship_amount[4] = {4,3,2,1};
std::string error_log;
bool shoot(char field[][10],const short x,const short y){
    if ((x>10)||(x<0)||(y>10)||(y<0)) {
        error_log = "can`t shoot by theese coord";
        return false;
    }
    field[x][y] = ((field[x][y]=='#')?'@':'*');
    error_log = "";
    return true;
}

bool win_check(const char field[][10]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (field[i][j]=='#') return false;
        }
    }
    return true;
}

bool place_ship(char field[][10], const short x1,const short y1,const short x2 ,const short y2 ,const short size){
    // coord check
    if ((x1==x2)&&(y1==y2)&&(size > 1)) { error_log = "cant place ship in these coord (incorrect coord)"; return false;}
    if ((x1<0)||(y1<0)||(x2<0)||(y2<0)||(size<1)) { error_log = "cant place ship in these coord (incorrect coord)"; return false;}
    if ((x1>9)||(y1>9)||(x2>9)||(y2>9)||(size>4)) { error_log = "cant place ship in these coord (incorrect coord)"; return false;}
    
    
    
    
    // horizontal place
    if (y1==y2) {
        // find less coord
        int x = (x1<x2?x1:x2);
    
        // first check
        for (int i=x;i<x+size;i++){
            if (field[y1][i]=='#') { error_log = "cant place ship in these coord (cood already occupied)"; return false;}
        }
        // then place
        for (int i=x;i<x+size;i++){
            field[y1][i] = '#';
        }
        error_log = "";
        return true;
    }
    // vertical place
    if (x1==x2) {
        // find less coord
        int y = (y1<y2?y1:y2);

        // first check
        for (int i=y;i<y+size;i++){
            if (field[i][x1]=='#') {return false; error_log = "cant place ship in these coord (cood already occupied)";}
        }
        //then place
        for (int i=y;i<y+size;i++){
            field[i][x1] = '#';
        }
        error_log = "";
        return true;
    }
    // non vertical or horizontal means wrong
    return false;
    error_log = "cant place ship in these coord (ship placeable only horizontaly or verticaly)";
}

void draw_battle_field(const char p1_field[][10], const char p2_field[][10], const bool turn){
    std::cout << "Player " << (turn?'1':'2') << " turn"<< std::endl;
    std::cout << "  1 2 3 4 5 6 7 8 9" << spaces <<  "  1 2 3 4 5 6 7 8 9" << std::endl;
    for (int i=0;i<10;i++){
        
        std::cout << i << ' ';
        for (int j=0;j<10;j++){
            if(p1_field[i][j] == '#') std::cout << (turn?'#':'~');
            else std::cout << p1_field[i][j] << ' ';
        }
        
        std::cout << spaces << i << ' ';
        for (int j=0;j<10;j++){
            if(p2_field[i][j] == '#') std::cout << (turn?'~':'#');
            else  std::cout << p2_field[i][j] << ' ';
        }
        

    }
    std::cout << std::endl;
    std::cout << std::endl << (error_log.empty()?" ":"Error: ") << error_log << std::endl;
}

void draw_build_field(const char field[][10],const short ship_amount[]){
    std::cout << "  0 1 2 3 4 5 6 7 8 9" << std::endl;
    for (int i=0;i<10;i++){       
        std::cout << i << ' ';
        for (int j=0;j<10;j++){
            std::cout << field[i][j] << ' '; 
        }
        std::cout << std::endl;    
    }   

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << spaces << "#### x " << ship_amount[3] << std::endl;
    std::cout << spaces << "### x " << ship_amount[2] << std::endl;
    std::cout << spaces << "## x " << ship_amount[1] << std::endl;
    std::cout << spaces << "# x " << ship_amount[0] << std::endl; 
    std::cout << std::endl << (error_log.empty()?" ":"Error: ") << error_log << std::endl;
}

int main(){
   for (int i=0;i<10;i++){
       for (int j=0;j<10;j++){
           p1_field[i][j] = '~';
           p2_field[i][j] = '~';
       }
   }

   //building faze
    { 
        // player 1 place ships faze    
         int x1,y1,x2,y2,size;
        for (int i=0;i<4;i++){ // '#' ships place
            do {
                system("cls");
                std::cout << "Player 1 please place your sheep" << std::endl;
                draw_build_field(p1_field,ship_amount);
                std::cout << std::endl << "Enter your '#' ship coord  (x y): ";
                std::cin >> x1; std::cin >> y1;
                x2 = x1; y2 = y1; size = 1;
            } while (!place_ship(p1_field,x1,y1,x2,y2,size));
            ship_amount[0] --;
        }
        for (int i=0;i<3;i++){ // '##' ships place
            do {
                system("cls");
                std::cout << "Player 1 please place your sheep"  << std::endl;
                draw_build_field(p1_field,ship_amount);
                std::cout << std::endl << "Enter your '##' ship coord  (x1 y1 x2 y2): ";
                std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2; size =2;
            } while (!place_ship(p1_field,x1,y1,x2,y2,size));
            ship_amount[1] --;
        }
        for (int i=0;i<2;i++){ // '###' ships place
            do {
                system("cls");
                std::cout << "Player 1 please place your sheep"  << std::endl;
                draw_build_field(p1_field,ship_amount);
                std::cout << std::endl << "Enter your '###' ship coord  (x1 y1 x2 y2): ";
                std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2; size = 3;
            } while (!place_ship(p1_field,x1,y1,x2,y2,size));
            ship_amount[2] --;
        }
        // '####' ships place
        do {
            system("cls");
            std::cout << "Player 1 please place your sheep"  << std::endl;
            draw_build_field(p1_field,ship_amount);
            std::cout << std::endl << "Enter your '####' ship coord  (x1 y1 x2 y2): ";
            std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2; size = 4;
        } while (!place_ship(p1_field,x1,y1,x2,y2,size));
        
        // player 2 place ships faze    
        for (int i=0;i<4;i++) ship_amount[i] = 4-i; // ship_amount = {4,3,2,1}

        for (int i=0;i<4;i++){ // '#' ships place
            do{
                system("cls");
                std::cout << "Player 2 please place your sheep" << std::endl;
                draw_build_field(p2_field,ship_amount);
                std::cout << std::endl << "Enter your '#' ship coord  (x y): ";
                std::cin >> x1; std::cin >> y1;
                x2 = x1; y2 = y1; size = 1;
            } while (!place_ship(p2_field,x1,y1,x2,y2,size));
            ship_amount[0] --;
        }
        for (int i=0;i<3;i++){ // '##' ships place
            do{
                system("cls");
                std::cout << "Player 2 please place your sheep"  << std::endl;
                draw_build_field(p2_field,ship_amount);
                std::cout << std::endl << "Enter your '##' ship coord  (x1 y1 x2 y2): ";
                std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2; size =2;
            } while (!place_ship(p2_field,x1,y1,x2,y2,size));
            ship_amount[1] --;
        }
        for (int i=0;i<2;i++){ // '###' ships place
            do{
                system("cls");
                std::cout << "Player 2 please place your sheep"  << std::endl;
                draw_build_field(p2_field,ship_amount);
                std::cout << std::endl << "Enter your '###' ship coord  (x1 y1 x2 y2): ";
                std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2; size = 3;
            } while (!place_ship(p2_field,x1,y1,x2,y2,size));
            ship_amount[2] --;
        }
        // '####' ships place
        x1=-1;y1=-1;x2=-1;y2=-1;size=-1;
        do{
            system("cls");
            std::cout << "Player 2 please place your sheep"  << std::endl;
            draw_build_field(p2_field,ship_amount);
            std::cout << std::endl << "Enter your '####' ship coord  (x1 y1 x2 y2): ";
            std::cin >> x1; std::cin >> y1; std::cin >> x2; std::cin >> y2; size = 4;
        } while (!place_ship(p2_field,x1,y1,x2,y2,size));
    }
   //batle faze
    {
        bool turn = true;
        int x,y;
        while (!win_check((turn?p1_field:p2_field))){
            do{
            system("cls");
            draw_battle_field(p1_field,p2_field,turn);
                std::cout << std::endl << "Enter your shoot coord (x y): ";
                std::cin >> x; std::cin >> y; 
            }while (!shoot((turn?p1_field:p2_field),x,y));
            turn = !turn;
        }
        system ("cls");
        std::cout << (turn?"First":"Second") << " player win! \n" << "Nice game!" << std::endl;
        system("pause");
    }
   
   
    
    return 0;
}
