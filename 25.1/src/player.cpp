#include "player.h"




Player::Player(std::string playlistPath)
{
    std::ifstream playlistFile;
    playlistFile.open(playlistPath);
    
    if (!playlistFile.is_open()) // push empty track in play list
    {
        Track dummyTrack("");
        playlist.push_back(dummyTrack);
    }
   
    std::string line;
    while (std::getline(playlistFile,line))
    {
        Track dummyTrack(line);
        playlist.push_back(dummyTrack);
    }

    // inicialize start player parametrs
    current_track = -1;
    state = Player::states::STOP;
    playlistFile.close();
};


std::string Player::get_current_track()
{
    std::string retStr = "";
        
    if (((state == Player::states::PLAY)||
        (state == Player::states::PAUSE))&&
        (current_track < playlist.size())&&
        (current_track >= 0))
    {
        retStr += playlist[current_track].get_name() + " ";
        retStr += playlist[current_track].get_duaration_str() + " ";
        retStr += playlist[current_track].get_date_str();   
        return retStr;
    }

    retStr = "no song is being performed right now";
    return retStr;
};

int Player::play(std::string trackName)
{
    if (state == Player::states::PAUSE)
    {
        state = Player::states::PLAY;
        return 0;
    }
    
    if (state == Player::states::STOP)
    {
        for (int i=0;i<playlist.size();i++)
        {
            if (playlist[i].get_name() == trackName)
            {
                current_track = i;
                state = Player::states::PLAY;
                return 0;
            }
        }
        return 1;
    }

    if (state == Player::states::PLAY)
    {
        return 0;
    }

    if (state == Player::states::ERROR)
    {
        return 1;
    }

    return 1;
};

void Player::stop()
{
    current_track = -1;
    state = Player::states::STOP;
};

void Player::pause()
{
    state = Player::states::PAUSE;
}

void Player::next()
{
    srand(std::time(nullptr));
    int num = std::rand()%playlist.size();
    current_track = num;
    state = Player::states::PLAY;
};


std::string Player::get_state()
{
    switch (state)
    {
    case Player::states::PLAY:
        return "PLAY";
    case Player::states::PAUSE:
        return "PAUSE";
    case Player::states::STOP:
        return "STOP";
    default:
        return "ERROR";
    }
    
}