#include <iostream>
#include <math.h>

struct vecStr{
    float x = 0.f;
    float y = 0.f;
};

vecStr add(vecStr v1, vecStr v2){
    vecStr resoult;
    resoult.x = v1.x + v2.x;
    resoult.y = v1.y + v2.y;
    return resoult;
};

vecStr sub(vecStr v1, vecStr v2){
    vecStr resoult;
    resoult.x = v1.x - v2.x;
    resoult.y = v1.y - v2.y;
    return resoult;
};

vecStr scale(vecStr v1, float scl){
    vecStr resoult;
    resoult.x = v1.x*scl;
    resoult.y = v1.y*scl;
    return resoult;
};


float len(vecStr v){
    float resoult;
    resoult = sqrt(v.x*v.x+v.y*v.y);
    return resoult;
};

vecStr normalize(vecStr v){
    vecStr resoult;
    float lenght = len(v);
    if (lenght != 0){ 
        resoult.x = v.x/lenght;  
        resoult.y = v.y/lenght;
    }

    return resoult;
};

int main(int argc, char** argv){

    std::cout << "Command list: add sub scl len nrm" << std::endl;
 
    //  add - add v1 to v2
    //  sub - subtraction v1 to v2
    //  scl - scale v to float number
    //  len - lenght of v
    //  nrm - normalize v
 
    std::string comand;
    std::cout << "Enter your command: ";
    std::cin >> comand;

    vecStr v1,v2,v,resVec;
    if (comand == "add"){
        std::cout << "enter your first vector(0.f 0.f): ";
        std::cin >> v1.x >> v1.y;
        std::cout << "enter your second vector(0.f 0.f): ";
        std::cin >> v2.x >> v2.y;
        resVec = add(v1,v2);
        std::cout << "resoult : " << resVec.x << " " << resVec.y << std::endl;
        return 0;
    }
    if (comand == "sub"){
        std::cout << "enter your first vector(0.f 0.f): ";
        std::cin >> v1.x >> v1.y;
        std::cout << "enter your second vector(0.f 0.f): ";
        std::cin >> v2.x >> v2.y;
        resVec = sub(v1,v2);
        std::cout << "resoult : " << resVec.x << " " << resVec.y << std::endl;
        return 0;
    }
    if (comand == "scl"){
        std::cout << "enter your vector(0.f 0.f): ";
        std::cin >> v.x >> v.y;
        std::cout << "enter your scale (0.f): ";
        float scl;
        std::cin >> scl;
        resVec = scale(v,scl);
        std::cout << "resoult : " << resVec.x << " " << resVec.y << std::endl;
        return 0;
    }
    if (comand == "len"){
        std::cout << "enter your vector(0.f 0.f): ";
        std::cin >> v.x >> v.y;
        float lenght = len(v);
        std::cout << "resoult : " << lenght << std::endl;
        return 0;
    }
    if (comand == "nrm"){
        std::cout << "enter your vector(0.f 0.f): ";
        std::cin >> v.x >> v.y;
        resVec = normalize(v);
        std::cout << "resoult : " << resVec.x << " " << resVec.y << std::endl;
        return 0;
    }

    std::cout << "Wrong command" << std::endl;
    return 0;
}