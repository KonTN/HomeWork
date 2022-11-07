#pragma once

#include <thread>
#include "string"
#include <mutex>

class Swimmer
{
    public:
        Swimmer(const Swimmer&);
        Swimmer(std::string &name, int speed);
        void start_swim();
        float get_floated_distance();
        std::string get_name();
    private:
        std::mutex m_floatedDistanceAccess;
        static void swim(Swimmer &s);
        std::string m_name;
        int m_speed;
        float m_floatedDistance;
};