#include <iostream>
#include <string>
#include <fstream>

enum direction {
    LEFT = 0,
    UP,
    RIGHT,
    DOWN
};

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

struct fieldStruct{
    static int width = 40;
    static int height = 20;
    char buff[width*height];
};

void make_field(const entity enemy[], const int enemyCounter,const entity player, 
                fieldStruct f){

    for (int i = 0; i < f.height; i++){
        for (int j =0 ; j < f.width; j++){
            f.buff[i*f.width+j] = '.';
        }
    }
    for (int i=0;i<enemyCounter;i++){
        if (enemy[i].hp > 0){
            f.buff[enemy[i].coord.y*f.width+enemy[i].coord.x] = 'E';
        }
    }
    f.buff[player.coord.y*f.width+player.coord.x] = 'P';
}

void print_field(const fieldStruct& f){
    
    for (int i = 0; i<f.height;i++){
        for (int j = 0; j<f.width;j++){
          std::cout << f.buff[i*f.width+j];
        }
        std::cout << std::endl;
    }
}

int deal_damage(const entity sourse, entity recipient){
    if (sourse.hp <= 0) {
        std::cout << "Error: zero hp entity ("<< sourse.name ") tries do damage";
        return 1;
    }
    if (sourse.dmg < 0){
        std::cout << "Error: entity ("<< sourse.name ") has negative damage";
        return 1;
    }
    int remainDmg = sourse.dmg;
    remainDmg -= recipient.armor;
    recipient.armor -= sourse.dmg;
    if (recipient.armor < 0)  recipient.armor = 0;
    if (remainDmg > 0) recipient.hp -= remainDmg;
    if (recipient.hp < 0) recipient.hp = 0;
    std::cout << sourse.name << " deal " << sourse.dmg << " to " << recipient.name << std::endl;
    std::cout << recipient.name << " now have " << recipient.armor << "armor and " << recipient.hp << " hp" << std::endl;
    return 0;
}


int make_move(const fieldStruct f, const entity sourse, const int dir){
    switch (dir)
    {
        case LEFT:
            if (f[sourse.coord.y*sqreen])
            break;
        case UP:
            /* code */
            break;
        case RIGHT:
            /* code */
            break;
        case DOWN:
            /* code */
            break;
        
        default:
            std::cout << "Error: wrong movement direction command";
            return 1;
            break;
    }
}

int main(int argc, char** argv){
    
    // initialization
    fieldStruct field;
    const int enemyCounter = 5;
    const int sqreenWidth = 40; 
    const int sqreenHeihgt = 10;
    
    entity player;
    entity enemy[enemyCounter];
    
    

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
                make_movement(enemy,dir);
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