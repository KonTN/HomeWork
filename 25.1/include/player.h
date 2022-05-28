#pragma once


#include <vector>
#include <string>

#include "track.h"

class Player
{
    public:
        Player(std::string playlistFilePath = "tracks.txt");

        void play(std::string name);
        void pause();
        void stop();
        void next();

        enum class states 
        {
            ERROR,
            PLAYING,
            PAUSE,
            STOPED,
        };
        states get_state();
        
        Track get_track();

        ~Player();
    private:
        states currentState;
        Track* currentTrackPtr;
        std::vector<Track> playlist;
};