#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>

struct vector 
{
    int x = 0;
    int y = 0;
};

struct entity 
{
    enum entityTypes {
        PLAYER,
        ENEMY,
        UNKNOWN 
    };

    std::string name;
    int hp = 0;
    int arm = 0;
    int dmg = 0;
    int type = UNKNOWN;
    vector coord;
};

struct sqreen 
{
    int width = 40;
    int height = 40;
};

struct scene{
    std::vector<entity> entityVec;
    int width = 0;
    int height = 0;
    std::vector<std::string> eventLog;
};

int print_frame(const std::string& frameBuff,const sqreen frameResolution)
{
    if (frameResolution.height*frameResolution.width != frameBuff.size())
    {
        std::cout << "Error: frame resolution mismatch";
        return 0;
    }

    std::cout << std::endl;
    for (int i = 0; i < frameResolution.width; i++ )
    {
        std::cout << "=";
    }
    std::cout << std::endl;

    for(int i = 0; i < frameResolution.height; i++)
    {
        for (int j = 0; j < frameResolution.width; j++)
        {
            std::cout << frameBuff[i*frameResolution.width+j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < frameResolution.width; i++ )
    {
        std::cout << "=";
    }
    std::cout << std::endl;
    return 0;
}

int make_frame(const scene& frameScene, std::string& frameBuff, const sqreen frameResolution)
{
    for (char & c : frameBuff) c = '.'; // clear frame buff
    
    for (const entity & a : frameScene.entityVec)
    {
        if (a.hp > 0)
        {
            if (((a.coord.x >= 0)&&(a.coord.x < frameResolution.width))&&
                ((a.coord.y >= 0)&&(a.coord.y < frameResolution.height))) 
            {
                if (a.type == entity::entityTypes::ENEMY) 
                {
                    frameBuff[a.coord.y*frameResolution.width+a.coord.x] = 'E';
                }
                if (a.type == entity::entityTypes::PLAYER) 
                {
                    frameBuff[a.coord.y*frameResolution.width+a.coord.x] = 'P';
                }

            }
        }
    }
    return 0;
}

int make_move(entity& subject, vector direction,scene& frameScene)
{       
    entity subjectCopy = subject;
    subjectCopy.coord.x += direction.x;
    subjectCopy.coord.y += direction.y;

    if (subjectCopy.coord.x < 0) subjectCopy.coord.x = 0;
    if (subjectCopy.coord.x >= frameScene.width) subjectCopy.coord.x = frameScene.width-1;
    if (subjectCopy.coord.y < 0) subjectCopy.coord.y = 0;
    if (subjectCopy.coord.y >= frameScene.height) subjectCopy.coord.y = frameScene.height-1;

    for (entity & a : frameScene.entityVec)
    {
        if (a.hp > 0)
        {
            if ((subjectCopy.coord.x == a.coord.x)&&(subjectCopy.coord.y == a.coord.y)){ // if coord already occupied
                // roll back movement
                subjectCopy.coord.x -= direction.x;
                subjectCopy.coord.y -= direction.y;
                
                if (subjectCopy.type != a.type) // enemy can`t deal damage to enemy as player to player 
                {
                    // deal damage
                    int dealDmg = subjectCopy.dmg - a.arm;
                    if (dealDmg < 0) dealDmg = 0;
                    a.arm -= subjectCopy.dmg;
                    if (a.arm < 0) a.arm = 0;
                    a.hp -= dealDmg;
                    if (a.hp < 0) a.hp = 0;
                    frameScene.eventLog.push_back(subjectCopy.name + " deal " + std::to_string(dealDmg) + " damage to " + a.name);
                    subject = subjectCopy;
                    return 0;
                }
                frameScene.eventLog.push_back(subjectCopy.name + " try to occupt already occupied coord by " + a.name +" ("+std::to_string(subjectCopy.coord.x + direction.x)+":"+std::to_string(subjectCopy.coord.y + direction.y)+")");
                subject = subjectCopy;
                return 1;
            }
        }    
    }
    frameScene.eventLog.push_back(subjectCopy.name + " moved to "+std::to_string(subjectCopy.coord.x)+":"+std::to_string(subjectCopy.coord.y));
    subject = subjectCopy;
    return 0;
}

int load_save(std::string& frameBuff,scene& frameScene,const std::string savePath = "save.txt")
{
    // try open save file
    std::ifstream save;
    save.open(savePath);
    if (!save.is_open()){
        std::cout << "Error: can`t open save file (" << savePath << ")" << std::endl;
        return 1;
    }

    // read enviroment constances
    int sqrWidth,sqrHeight;
    save >> sqrWidth >> sqrHeight;
    frameScene.height = sqrHeight;
    frameScene.width = sqrWidth;
    // read frame buff
    frameBuff.resize(sqrHeight*sqrWidth);
    save >> frameBuff;
    int size = frameBuff.size();
    if (frameBuff.size() != sqrWidth*sqrHeight) {
        std::cout << "Error: save file reading error 1";
        return 1;
    }
    // read scene;
    int enemyAmmaunt;
    save >> enemyAmmaunt;
    entity dummyEnt;
    for (int i =0 ; i < enemyAmmaunt+1; i++){
       frameScene.entityVec.push_back(dummyEnt);
       save >> frameScene.entityVec[i].type;
       save >> frameScene.entityVec[i].name;
       save >> frameScene.entityVec[i].hp;
       save >> frameScene.entityVec[i].arm;
       save >> frameScene.entityVec[i].dmg;
       save >> frameScene.entityVec[i].coord.x;
       save >> frameScene.entityVec[i].coord.y;
    }  
    save.close();
    return 0;
}

int save_game(const std::string& frameBuff, const scene& frameScene,const sqreen& resolution,const std::string savePath = "save.txt")
{
    // try open save file
    std::ofstream save;
    save.open(savePath);
    if (!save.is_open()){
        std::cout << "Error: can`t open save file (" << savePath << ")" << std::endl;
        return 1;
    }

    // read enviroment constances
    save << resolution.width << std::endl << resolution.height<< std::endl;
    // read frame buff
    save << frameBuff<< std::endl;
    
    // read scene;
    save << frameScene.entityVec.size()-1<< std::endl;
    for (int i =0 ; i < frameScene.entityVec.size(); i++){
       save << frameScene.entityVec[i].type<< std::endl;
       save << frameScene.entityVec[i].name<< std::endl;
       save << frameScene.entityVec[i].hp<< std::endl;
       save << frameScene.entityVec[i].arm<< std::endl;
       save << frameScene.entityVec[i].dmg<< std::endl;
       save << frameScene.entityVec[i].coord.x<< std::endl;
       save << frameScene.entityVec[i].coord.y<< std::endl;
    }  
    save.close();
    return 0;
}


int main(int argc, char** argv)
{
     // set up enviroment
    const int enemyAmmaunt = 5;
    const sqreen sqreenResolution = {40,20};
    std::string frameBuff;
    scene gameScene;
    frameBuff.resize(sqreenResolution.height*sqreenResolution.width);    
    gameScene.height = sqreenResolution.height;
    gameScene.width = sqreenResolution.width;

    std::cout << "command list: 'new' 'load'" << std::endl;
    std::cout << "Please enter your command: ";
    std::string command;
    std::cin >> command;

    if ((command != "new")&&(command != "load"))
    {
        std::cout << "Error: wrong command" << std::endl;
        return 1;
    }
        
    if (command == "new"){
        
            // fill scene with enemy
            srand( time(0) ); // eneable random numbers

            for (int i = 0; i < enemyAmmaunt; i++)
            {
                entity dummyEnemy;
                dummyEnemy.type = entity::entityTypes::ENEMY;
                dummyEnemy.name = "Enemy#"+std::to_string(i);
                dummyEnemy.hp = 50+rand()%100;
                dummyEnemy.arm = rand()%50;
                dummyEnemy.dmg =  15+rand()%15;
                // move enemy to random free coordinate
                vector MoveVec;
                do 
                {
                    MoveVec = {rand()%gameScene.width,rand()%gameScene.height};

                }
                while (make_move(dummyEnemy,MoveVec,gameScene));
                gameScene.entityVec.push_back(dummyEnemy);
            }

            // set up player character
            entity dummyPlayer;
            
            std::cout << "Discribe your character" << std::endl;
            
            std::cout << "  Enter your name: ";
            std::cin >> dummyPlayer.name;
            
            std::cout << "  Enter your hp: ";
            std::cin >> dummyPlayer.hp;
            if (dummyPlayer.hp < 0) 
            {
                std::cout << "Error: invalid hp value" << std::endl;
                return 1;
            }

            std::cout << "  Enter your armor: ";
            std::cin >> dummyPlayer.arm;
            if (dummyPlayer.arm < 0) 
            {
                std::cout << "Error: invalid armor value" << std::endl;
                return 1;
            }

            std::cout << "  Enter your damage: ";
            std::cin >> dummyPlayer.dmg;
            if (dummyPlayer.dmg < 0) 
            {
                std::cout << "Error: invalid damage value" << std::endl;
                return 1;
            }

            // give player random position
            dummyPlayer.type = entity::entityTypes::ENEMY; // to don`t do damage to enemies
            while (make_move(dummyPlayer,{rand()%gameScene.width,rand()%gameScene.height},gameScene));
            dummyPlayer.type = entity::entityTypes::PLAYER; 
            
            gameScene.entityVec.push_back(dummyPlayer);

    }

    if (command == "load"){
        load_save(frameBuff,gameScene);
    }


    // start game loop
    bool quit = false;
    while(!quit)
        {
            // display frame;
            make_frame(gameScene,frameBuff,sqreenResolution);
            print_frame(frameBuff,sqreenResolution);
            
            // display event log;
            for (std::string event : gameScene.eventLog)
            {
                std::cout << event << std::endl;
            }
            // clear already shown logs
            gameScene.eventLog.clear();

            // print  '=' line afte log
            for (int i=0;i<sqreenResolution.width;i++)std::cout << "=";
            std::cout << std::endl;

            // player turn
                std::cout << "Command list : 'left' 'up' 'right' 'down' 'save'" << std::endl;
                std::cout << "Enter your command: ";
                std::cin >> command;

                // gameScene.entityVec[enemyAmmaunt] - always will be player entity
                if (command == "left") make_move(gameScene.entityVec[enemyAmmaunt],{-1,0},gameScene); 
                if (command == "up") make_move(gameScene.entityVec[enemyAmmaunt],{0,-1},gameScene); 
                if (command == "right") make_move(gameScene.entityVec[enemyAmmaunt],{1,0},gameScene); 
                if (command == "down") make_move(gameScene.entityVec[enemyAmmaunt],{0,1},gameScene); 
                if (command == "save")
                { 
                    save_game(frameBuff,gameScene,sqreenResolution);
                    quit = true;
                }
            // enemyes turn
                for (entity& e : gameScene.entityVec)
                {
                    if ((e.type == entity::entityTypes::ENEMY)&&(e.hp > 0))
                    {
                        vector rndVec = {(rand()%3)-1,(rand()%3)-1};
                        if (abs(rndVec.x)+abs(rndVec.y)==2){ // to move only 4 directions;
                            (rand()%2==1) ? rndVec.x = 0 : rndVec.y = 0;
                        }
                        if (abs(rndVec.x)+abs(rndVec.y)==0){ // to move only 4 directions;
                            (rand()%2==1) ? rndVec.x = 1 : rndVec.y = 1;
                        }
                        make_move(e,rndVec,gameScene);
                    }
                }
                
            // claculate win
            int enemyesHp = 0;
            for (entity e:gameScene.entityVec) 
            {
               if (e.type == entity::entityTypes::ENEMY) enemyesHp += e.hp;   
            }
            if (enemyesHp == 0){
                std::cout << gameScene.entityVec[enemyAmmaunt].name << " wins, congratulation!" << std::endl;
                quit = true;
            }
            if (gameScene.entityVec[enemyAmmaunt].hp == 0) 
            {
                std::cout << gameScene.entityVec[enemyAmmaunt].name << " dies, game over" << std::endl;
                quit = true;
            }      
        }

    return 0;
}
