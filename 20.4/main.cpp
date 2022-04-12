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
        if (((a.coord.x > 0)&&(a.coord.x <= frameResolution.width))&&
            ((a.coord.y > 0)&&(a.coord.y <= frameResolution.height))) 
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
    return 0;
}

int make_move(entity& subject, vector direction,scene& frameScene)
{       
    subject.coord.x += direction.x;
    subject.coord.y += direction.y;

    if (subject.coord.x < 0) subject.coord.x = 0;
    if (subject.coord.x >= frameScene.width) subject.coord.x = frameScene.width;
    if (subject.coord.y < 0) subject.coord.y = 0;
    if (subject.coord.y >= frameScene.height) subject.coord.y = frameScene.height;

    for (entity & a : frameScene.entityVec)
    {
        if ((subject.coord.x == a.coord.x)&&(subject.coord.y == a.coord.y)){ // if coord already occupied
            // roll back movement
            subject.coord.x -= direction.x;
            subject.coord.y -= direction.y;
            
            if (subject.type != a.type) // enemy can`t deal damage to enemy as player to player 
            {
                // deal damage
                int dealDmg = subject.dmg - a.arm;
                if (dealDmg < 0) dealDmg = 0;
                a.arm -= subject.dmg;
                if (a.arm < 0) a.arm = 0;
                a.hp -= dealDmg;
                frameScene.eventLog.push_back(subject.name + " deal " + std::to_string(dealDmg) + " damage to " + a.name);
                return 0;
            }
            frameScene.eventLog.push_back(subject.name + " try to occupt already occupied coord ("+std::to_string(subject.coord.x + direction.x)+":"+std::to_string(subject.coord.y + direction.y)+")");
            return 1;
        }
        
    }
    frameScene.eventLog.push_back(subject.name + " moved to "+std::to_string(subject.coord.x)+":"+std::to_string(subject.coord.y));
    return 0;
}

int main(int argc, char** argv)
{
    const int enemyAmmaunt = 5;
    const sqreen sqreenResolution = {40,20};
    std::string frameBuff;
    scene gameScene;

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
        // set up enviroment
            // enciroment constants
            frameBuff.resize(sqreenResolution.height*sqreenResolution.width);
            
            // create scene
                gameScene.height = sqreenResolution.height;
                gameScene.width = sqreenResolution.width;

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
                if (command == "right") make_move(gameScene.entityVec[enemyAmmaunt],{0,1},gameScene); 
                if (command == "down") make_move(gameScene.entityVec[enemyAmmaunt],{0,1},gameScene); 
            

            // enemies turn
                for (entity e : gameScene.entityVec)
                {
                    if ((e.type == entity::entityTypes::ENEMY)&&(e.hp > 0))
                    {
                        vector rndVec = {(rand()%3)-1,(rand()%3)-1};
                        if (abs(rndVec.x)+abs(rndVec.y)!=1){ // to move only 4 directions;
                            (rand()%2==1) ? rndVec.x = 0 : rndVec.y = 0;
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
