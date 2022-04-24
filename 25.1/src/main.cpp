#include <iostream>
#include <string>
#include <fstream>
#include "player.h"


int main()
{
    std::cout << "-----------------------\n";
    std::cout << "      player sim\n";
    std::cout << "-----------------------\n";
    std::cout << "command list:\n";
    std::cout << "  'play'\n  'pause'\n  'stop'\n  'exit'\n";
    std::cout << "-----------------------\n";
    std::cout << "playlist: \n";
    
    std::ifstream playlistFile;
    playlistFile.open("play.txt");
    if (!playlistFile.is_open()) return 1;
    std::string line;
    while (std::getline(playlistFile,line))
    {
        std::cout << "  " << line << std::endl;
    }
    playlistFile.close();
    std::cout << "-----------------------\n";
    std::cout << "Enter your command: " << std::endl;
    
    Player player("play.txt");
    std::string command;
    do {
        std::cin >> command;
        if (command == "play")
        {
            std::string name = "";

            if (player.get_state()=="PLAY") continue; // if player already playing
            // we has nothond to do
            if (player.get_state()=="PAUSE")
            {
                player.play(name);
                std::cout << player.get_current_track() << std::endl;
                continue;    
            }
            
            std::cout << "Enter Track name:";
            std::cin >> name;
            if (player.play(name))
            {
                std::cout << "Error: cant find track with " << name << " name" << std::endl;
            }
            else std::cout << player.get_current_track() << std::endl;
        }

        if (command == "pause")
        {
            if (player.get_state() == "PLAY")
            {
                std::cout << "Player has been paused" << std::endl;
                player.pause();
            }
        }
        
        if (command == "next")
        {
            std::cout << "playing next track" << std::endl;
            player.next();
            std::cout  << player.get_current_track() << std::endl;;
        }
        
        if (command == "stop")
        {
            if ((player.get_state() == "PLAY")||(player.get_state()=="PAUSE"))
            {
                std::cout << "stop playing music" << std::endl;
                player.stop();
            }
        }

    } while (command != "exit");
    std::cout << "" << std::endl;


    return 0;
}