#include "player.h"

#include <fstream>

Player::Player(std::string playlistFilePath)
{

    // parse playlist file
        std::ifstream playlistFile;
        playlistFile.open(playlistFilePath);

        if (playlistFile.is_open()) // start loading tracks
        {
            std::string buff = "";
            while (std::getline(playlistFile,buff))
            {
                Track dummy(buff);
                playlist.push_back(dummy);
            }
        }
        playlistFile.close();

    if (playlist.empty()) // if can't load any track
        currentState = states::ERROR;
    else 
        currentState = states::STOPED;
    
    currentTrackPtr = nullptr;
}

Player::states Player::get_state()
{
    return currentState;
}

Track Player::get_track()
{
    if (currentTrackPtr != nullptr)
    {
        Track retTrack("");
        retTrack = *currentTrackPtr;
        return *currentTrackPtr;
    }
    else 
    {
        Track emptyTrack("");
        return emptyTrack;
    }
}

void Player::play(std::string name)
{
    switch (currentState)
    {
        case states::STOPED:
            for (Track& trk : playlist)
            {
                if (trk.get_name() == name)
                {
                    currentTrackPtr = &trk;
                    currentState = states::PLAYING;
                    break;
                }
            }
            if (currentState == states::PLAYING) break;
            currentTrackPtr = nullptr;
            currentState = states::STOPED;
        break;

        case states::PAUSE:
            currentState = states::PLAYING;
        break;
    } 
}

void Player::pause()
{
    if (currentTrackPtr != nullptr)
        currentState = states::PAUSE;
}       

void Player::stop()
{
    currentState = states::STOPED;
    currentTrackPtr = nullptr;
}

void Player::next()
{
    currentState = states::PLAYING;
    srand(std::time(nullptr));
    currentTrackPtr = &playlist[rand()%playlist.size()];
}


Player::~Player()
{

}