#include <iostream>
#include <fstream>
#include "track.h"
#include "player.h"

int main(int argc, char** argv) {
    //start init
    Player plr("tracks.txt");
    
    // print header
        std::cout << "-----------------------\n";
        std::cout << "      player sim\n";
        std::cout << "-----------------------\n";
        std::cout << "command list:\n";
        std::cout << "  'play'\n  'pause'\n  'stop'\n  'exit'\n";
        std::cout << "-----------------------\n";
        std::cout << "playlist: \n";
        // pring playlist 
            std::ifstream playlistFile;
            playlistFile.open("tracks.txt");
            if (!playlistFile.is_open()) return 1;
            std::string line;
            while (std::getline(playlistFile,line))
            {
                std::cout << "  " << line << std::endl;
            }
            playlistFile.close();
        std::cout << "-----------------------\n";
        std::cout << "Enter your command: " << std::endl;
        
    // sim loop
    std::string command;
    do {
            
        if (plr.get_state() == Player::states::ERROR) 
        {
            std::cout << "Player ERROR" << std::endl;
            return 1;
        }

        std::cin >> command; // get command
        
        if (command == "play") 
        {
            if (plr.get_state() == Player::states::STOPED)
            {
                std::string name;
                std::cout << "Enter song name: ";
                std::cin >> name;
                plr.play(name);
                if (plr.get_state() == Player::states::PLAYING) // if we found song with that name in player playlist 
                {
                    std::cout << "PLAY: " << plr.get_track().get_info() << std::endl;
                    
                }
                else std::cout << "Can't find any \"" << name << "\" track" << std::endl;
                continue;
            }
            if (plr.get_state() == Player::states::PAUSE)
            {
                std::cout << "PLAY: " << plr.get_track().get_info() << std::endl; 
            }
            continue;
        }

        if (command == "pause")
        {
            if (plr.get_state() == Player::states::PLAYING)
            {
                plr.pause();
                std::cout << "player: PAUSE" << std::endl;
            }
            continue;
        }
        
        if (command == "next")
        {
           plr.next();
           std::cout << "PLAY: " << plr.get_track().get_info() << std::endl;
           continue;
        }
        
        if (command == "stop")
        {
           if ((plr.get_state() == Player::states::PLAYING)||(plr.get_state() == Player::states::PAUSE))
           {
               plr.stop();
               std::cout << "player: STOP" << std::endl;
           }
           continue;
        }

        if (command == "exit") continue;
        
        std::cout << "Unknown command: " << command << std::endl;

    } while (command != "exit");
    
    return 0;
}
