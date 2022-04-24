#pragma once

#include <vector>
#include <fstream>
#include "track.h"

class Player
{
    public:
        Player(std::string playlistPath = "playlist.txt");
        
        std::string get_current_track();
        std::string get_state();
        
        int play(std::string trackName);
        void stop();
        void pause();
        void next();
        
    private:
        enum class states
        {
            PLAY,
            STOP,
            PAUSE,
            ERROR
        };

        std::vector<Track> playlist;
        states state;
        int current_track;
};