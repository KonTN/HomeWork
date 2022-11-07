#include "swimmer.h"
#include <thread>
#include <functional>

Swimmer::Swimmer(const Swimmer &s)
{
    m_floatedDistance = s.m_floatedDistance;
    m_name = s.m_name;
    m_speed = s.m_speed;

}
Swimmer::Swimmer(std::string &name, int speed)
{
  m_name = name;
  m_speed = speed;
  m_floatedDistance = 0;
}

void Swimmer::swim(Swimmer& s)
{
    while (s.m_floatedDistance < 100)
    {
        s.m_floatedDistanceAccess.lock();
        s.m_floatedDistance += (float)s.m_speed/100;
        if (s.m_floatedDistance > 100) s.m_floatedDistance = 100;
        s.m_floatedDistanceAccess.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds (10));
    }
}

void Swimmer::start_swim()
{
    std::thread thr(Swimmer::swim,std::ref(*this));
    thr.detach();
}

float Swimmer::get_floated_distance()
{
    int distance;
    m_floatedDistanceAccess.lock();
    distance = m_floatedDistance;
    m_floatedDistanceAccess.unlock();

    return distance;
}

std::string  Swimmer::get_name()
{
    return m_name;
}