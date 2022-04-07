#include <iostream>
#include <string>
#include <fstream>

struct point{
    int x = 0;
    int y = 0;
};

struct entity {
    std::string name;
    int hp = 0;
    int armor = 0;
    int dmg = 0;
    point coord;
};

void make_field(const entity enemy[], const int enemyCounter,const entity player, 
                char* fieldBuff, const int width, const int height){

    for (int i = 0; i < height; i++){
        for (int j =0 ; j < width; j++){
            fieldBuff[i*width+j] = '.';
        }
    }
    for (int i=0;i<enemyCounter;i++){
        if (enemy[i].hp > 0){
            fieldBuff[enemy[i].coord.y*width+enemy[i].coord.x] = 'E';
        }
    }
    fieldBuff[player.coord.y*width+player.coord.x] = 'P';
}

int print_field(const char* fieldBuff,const int width,const int height){
    
    for (int i = 0; i<height;i++){
        for (int j = 0; j<width;j++){
          std::cout << fieldBuff[i*width+j];
        }
        std::cout << std::endl;
    }
    return 0;
}



int main(int argc, char** argv){
    
    // initialization
    const int enemyCounter = 5;
    const int sqreenWidth = 40; 
    const int sqreenHeihgt = 10;
    
    entity player;
    entity enemy[enemyCounter];
    
    char field[sqreenHeihgt*sqreenWidth];
    
    // format main menu
    for (int i = 0;i<sqreenWidth;i++)std::cout << "=";
    std::cout << std::endl;
    std::cout << "      Main menu: " << std::endl;
    std::cout << "        new" << std::endl;
    std::cout << "        load" << std::endl;   
    for (int i = 0;i<sqreenWidth;i++)std::cout << "=";
    std::cout << std::endl;
    std::cout << "Enter your command: ";
    std::string buff;
    std::cin >>buff;
    if ((buff != "new")&&(buff != "load")){
        std::cout << "wrong command";
        return 0;
    }

    if (buff == "new"){

        // clear field
        for (int i=0;i<sqreenHeihgt;i++){
            for (int j=0;j<sqreenWidth;j++){
                field[i*sqreenWidth+j] = '.';
            }
        }

        // create enemy and player
        srand(time(NULL)); 

        for (int i = 0; i<enemyCounter;i++){
            enemy[i].name = "Enemy#" + i;
            enemy[i].armor = rand()%50;
            enemy[i].hp = 50+rand()%100;
            enemy[i].dmg = 15+rand()%15;
            do{
            enemy[i].coord.x = rand()%(sqreenWidth-1);
            enemy[i].coord.y = rand()%(sqreenHeihgt-1);
            }
            while(field[enemy[i].coord.y*sqreenWidth+enemy[i].coord.x] == 'E');
            field[enemy[i].coord.y*sqreenWidth+enemy[i].coord.x] = 'E';             
        }
        std::cout << "Please enter your name: ";
        std::cin >> player.name;
        if (player.name == "\n") player.name = "Pavel";

        std::cout << "             your hp: ";
        std::cin >> player.hp;
        if (player.hp <= 0) player.hp = 100;

        std::cout << "             your armor: ";
        std::cin >> player.armor;
        if (player.armor < 0) player.armor = 0;

        std::cout << "             your dmg: ";
        std::cin >> player.dmg;
        if (player.dmg < 0) player.dmg = 1;
        
        do{
            player.coord.x = rand()%(sqreenWidth-1);
            player.coord.y = rand()%(sqreenHeihgt-1);
        }
        while(field[player.coord.y*sqreenWidth+player.coord.x] == 'E');
        field[player.coord.y*sqreenWidth+player.coord.x] = 'P';             
        
    }
    if (buff == "load"){
        // load save
        std::ifstream saveFile;
        saveFile.open("save.txt");
        if (!saveFile.is_open()){
            std::cout << "Error: can`t open save file";
            return 1;
        }
        // init section       
        for (int i = 0; i<enemyCounter;i++){
            enemy[i].name = "Enemy#" + i;
            saveFile >> enemy[i].armor;
            saveFile >> enemy[i].hp;
            saveFile >> enemy[i].dmg;
            saveFile >> enemy[i].coord.x;
            saveFile >> enemy[i].coord.y;
            field[enemy[i].coord.y*sqreenWidth+enemy[i].coord.x] = 'E';             
        }
        saveFile >>  player.name;
        saveFile >>  player.hp;
        saveFile >>  player.armor;
        saveFile >>  player.dmg;
        saveFile >> player.coord.x;
        saveFile >> player.coord.y;
        field[player.coord.y*sqreenWidth+player.coord.x] = 'P';

        saveFile >> field;

        saveFile.close();             
    }

    // start game loop
    int  enemyHp = 0;
    for (int i=0;i<enemyCounter;i++) enemyHp += enemy[i].hp;
    while ((enemyHp > 0)&&(player.hp > 0)){
        // calculate enemy movement
        for (int i = 0;i < enemyCounter; i++){
            if (enemy[i].hp>0){
                int dir = rand()%4;
                switch (dir)
                {
                case 0:
                    if (enemy[i].coord.x-1 >= 0) {
                        if (field[enemy[i].coord.y*sqreenWidth+(enemy[i].coord.x-1)] == '.'){
                            enemy[i].coord.x --;
                        }
                        if (field[enemy[i].coord.y*sqreenWidth+(enemy[i].coord.x-1)] == 'P'){
                            player.hp -=enemy[i].dmg-player.armor;
                            player.armor -= enemy[i].dmg;
                            std::cout << "Player take " << enemy[i].dmg << " damage from " << enemy[i].name << std::endl;
                        }
                    }
                    break;
                case 1:
                    if (enemy[i].coord.y-1 >= 0) {
                        if (field[(enemy[i].coord.y-1)*sqreenWidth+enemy[i].coord.x] == '.'){
                            enemy[i].coord.y --;
                        }
                        if (field[(enemy[i].coord.y-1)*sqreenWidth+enemy[i].coord.x] == 'P'){
                            player.hp -=enemy[i].dmg-player.armor;
                            player.armor -= enemy[i].dmg;
                            std::cout << "Player take " << enemy[i].dmg << " damage from " << enemy[i].name << std::endl;
                        }
                    }
                    break;
                case 2:
                    if (enemy[i].coord.x+1 <= sqreenWidth) {
                        if (field[enemy[i].coord.y*sqreenWidth+(enemy[i].coord.x+1)] == '.'){
                            enemy[i].coord.x ++;
                        }
                        if (field[enemy[i].coord.y*sqreenWidth+(enemy[i].coord.x+1)] == 'P'){
                            player.hp -=enemy[i].dmg-player.armor;
                            player.armor -= enemy[i].dmg;
                            std::cout << "Player take " << enemy[i].dmg << " damage from " << enemy[i].name << std::endl;
                        }
                    }
                    break;
                case 3:
                    if (enemy[i].coord.y+1 <= sqreenHeihgt) {
                        if (field[(enemy[i].coord.y+1)*sqreenWidth+enemy[i].coord.x] == '.'){
                            enemy[i].coord.y ++;
                        }
                        if (field[(enemy[i].coord.y+1)*sqreenWidth+enemy[i].coord.x] == 'P'){
                            player.hp -=enemy[i].dmg-player.armor;
                            player.armor -= enemy[i].dmg;
                            std::cout << "Player take " << enemy[i].dmg << " damage from " << enemy[i].name << std::endl;
                        }
                    }
                    break;
                }
            }
        }
        
        // cout game sqreen
        make_field(enemy,enemyCounter,player,field,sqreenWidth,sqreenHeihgt);
        for (int i=0;i<sqreenWidth;i++) std::cout << "=";
        std::cout << std::endl;
        print_field(field, sqreenWidth, sqreenHeihgt);
        for (int i=0;i<sqreenWidth;i++) std::cout << "=";
        std::cout << std::endl;
        std::cout << "Commadn list: 'left' 'right' 'up' 'down'" << std::endl;
        for (int i=0;i<sqreenWidth;i++) std::cout << "=";
        std::cout << std::endl;
        std::cout << "Enter your command: ";
        std::string command;
        std::cin >> command;

        
        // input player movement; 
    }

    return 0;
}