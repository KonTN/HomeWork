#include <iostream>
#include <vector>
#include <string>


struct roomStr
{
    enum type {BEEDROOM,KICHEN,BATHROOM,CHILDRENROOM,LIVINGROOM,NOONE};
    int roomType = NOONE;
    int square = 0;
};

struct floorStr
{
    roomStr roms[4];
    
    int seelingHeight = 0;
    int roomsCounter = 0;
};

struct houseStr
{
    floorStr floors[3];

    int square = 0;
    int floorsCounter = 0;
    bool oven = false;    
};

struct ambarStr
{
    int square = 0;
};

struct garageStr
{
    int square = 0;
};

struct saunaStr
{
    int square = 0;
    bool oven = false;
};

struct regionStr
{
    int number;
    houseStr house;
    ambarStr ambar;
    garageStr garage;
    saunaStr sauna;

};



int main(int argv, char** argc){
    
    regionStr region;
    std::cout << "Enter region nuber: ";
    std::cin >> region.number;
    
    //house
    std::cout << "Discribe house" << std::endl;
    
    std::cout << "  Enter house square: ";
    std::cin >> region.house.square;
    
    std::cout << "  Enter the numer of floors in house: ";
    int floorCounter;
    std::cin >> floorCounter;
    region.house.floorsCounter = floorCounter;
    if ((floorCounter <=0)&&(floorCounter >3)){
        std::cout << "Error: wrong floor number";
        return 1;
    }

    for (int i = 0; i < floorCounter;i++){
        std::cout << "      Discribe " << i+1 <<" floor"<< std::endl;
        std::cout << "      Enter floor height: ";
        std::cin >> region.house.floors[i].seelingHeight;
        std::cout << "      Enter the number of rooms in that floor: ";
        int roomCounter;
        std::cin >> roomCounter;
        region.house.floors[i].roomsCounter = roomCounter;
        if ((roomCounter <2)||(roomCounter >4)) {
            std::cout << "Error: wrong room ammaunt";
            return 1;
        }
        for (int j=0;j<roomCounter;j++){
            std::cout << "          Discribe " << j+1 <<" room"<< std::endl;
            std::cout << "          Enter room square: ";
            std::cin >> region.house.floors[i].roms[j].square;
            std::cout << "          Enter room type: ";
            std::string ansver;
            const std::vector<std::string> roomstype = {"BEEDROOM","KICHEN","BATHROOM","CHILDRENROOM","LIVINGROOM"};
            std::cin >> ansver; 
            for (int k=0;k<roomstype.size();k++) {
                if (roomstype[k] == ansver){
                    region.house.floors[i].roms[j].roomType = k;
                }
            }
        }
    }

    char ansver;

    std::cout << "  this House has a oven (y/n): ";
    std::cin >> ansver;
    if (ansver == 'y') region.house.oven = true;


    // garage
    std::cout << "This area has a garage (y/n): ";
    std::cin >> ansver;
    if (ansver == 'y'){
        std::cout << "  Enter garage square: ";
        std::cin >> region.garage.square;
    }

    // ambar
    std::cout << "This area has a ambar (y/n): ";
    std::cin >> ansver;
    if (ansver == 'y'){
        std::cout << "  Enter ambar square: ";
        std::cin >> region.ambar.square;
    }

    // sauna
    std::cout << "This area has a sauna (y/n): ";
    std::cin >> ansver;
    if (ansver == 'y'){
        std::cout << "  Enter sayna square: ";
        std::cin >> region.sauna.square;
        std::cout << "  this sayna has a oven (y/n): ";
        std::cin >> ansver;
        if (ansver == 'y') region.sauna.oven = true; 
    }


    // calculate resoult
    float medHeight = 0.f;
    for (int i=0;i<region.house.floorsCounter;i++){
        medHeight += region.house.floors[i].seelingHeight;
    }
    std::cout << "Median seling height in house: " << medHeight / region.house.floorsCounter << std::endl;


    int bathroomCounter = 0;
    for (int i=0;i<region.house.floorsCounter;i++){
        for (int j=0;j<region.house.floors[i].roomsCounter;j++){
            if (region.house.floors[i].roms[j].roomType == region.house.floors[i].roms[j].BATHROOM) bathroomCounter  ++;
        }
    }
    std::cout << "This house has " << bathroomCounter << " bathrooms" << std::endl;

    return 0;

}