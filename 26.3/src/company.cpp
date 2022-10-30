#include <iostream>

#include "company.h"

company::Worker::Worker()
{
    m_name = "UNKNOWN";
    m_job = -1;
}

company::Worker::Worker(std::string name)
{
    m_name = name;
    m_job = 0;
}

bool company::Worker::free_job_check()
{
    return !m_job;
}
void company::Worker::take_job(char job)
{
    if ((job != 'A')&&(job != 'B')&&(job != 'C'))
    {
        std::cout << "\t" << m_name << " recived wrong job (" << job << ")\n";
    }
    else 
    {
        std::cout << "\t"  << m_name << " recived " << job << " job\n";
        m_job = job;
    }
} 

company::Manager::Manager(std::string name, int id, std::vector<Worker> team)
{
    m_name = name;
    m_id = id;
    m_team = team;
    m_free_team_size = m_team.size();
}

int company::Manager::give_job(int job)
{
    std::srand(job + m_id);
    int taskCount = rand()%(m_free_team_size+1);
    std::cout << m_name << " give team " << taskCount << " jobs: \n";
    if (taskCount == 0 ) return 0;
    for (Worker& w : m_team)
    {
        if (w.free_job_check())
        {
            w.take_job((char)(65+std::rand()%3));
            m_free_team_size -= 1;
            taskCount -= 1;
            if (taskCount == 0) break;
        }
    }
    if (m_free_team_size == 0) return 1;
    return 0;
}

bool company::Manager::operator==(Manager m)
{
    return m_id == m.m_id;
}

company::Director::Director(std::string name, std::vector<Manager> team)
{
    m_name = name;
    m_team = team;
    m_busy_team.clear();
}

bool company::Director::find_in_vec(std::vector<Manager> v, Manager fm)
{
    for (Manager m : v)
    {
        if (m == fm) return 1;
    }
    return 0;
}

int company::Director::give_job(int job)
{
    std::cout << m_name <<" how have a " << job << " job\n";
    for (Manager& m : m_team)
    {
        if (find_in_vec(m_busy_team,m)) continue;
        if(m.give_job(job))
        {
            m_busy_team.push_back(m);
            if (m_busy_team.size() == m_team.size()) return 0;
        }
    }
    return 1;
}