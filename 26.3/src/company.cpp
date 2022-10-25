#include "company.h"
#include <iostream>

company::Worker::Worker()
{
    m_name = "NONE_W";
    m_task = 0;
}

company::Worker::Worker(std::string name)
{
    m_name = name;
    m_task = 0;
}

void company::Worker::take_task(int task)
{
    m_task = task;
}

bool company::Worker::empty_task_check()
{
    return m_task == 0;
}

std::string company::Worker::job_report()
{
    if (((char)m_task != 'A')||((char)m_task != 'B')||((char)m_task != 'C'))
    {
        return m_name + " received wrong task (" + std::to_string(m_task) + ")";       
    }

    return m_name + " received task " + (char)m_task;
}



company::Manager::Manager()
{
    m_name = "NONE_M";
    m_task = 0;
    m_free_teamates.clear();
    m_busy_teamates.clear();
}

company::Manager::Manager(std::string name,int id, std::list<Worker> team)
{
    m_name = name;
    m_id = id;
    m_task = 0;
    m_free_teamates = team; 
}

void company::Manager::free_team()
{
    for (Worker& w: m_busy_teamates)
    {
        w.take_task(0);
        m_free_teamates.push_back(w);
    }
    m_busy_teamates.clear();

}

int company::Manager::give_task()
{    
    std::srand(m_id);
    int tasksCount = std::rand()%(m_free_teamates.size()+1);
    for (int i = 0; i < tasksCount; i++)
    {
        if (m_free_teamates.empty()) return 0;
        company::Worker dummy = m_free_teamates.front(); 
        dummy.take_task(65+rand()%2); // ascii 'A' 'B' or 'C'
        m_busy_teamates.push_back(dummy);
        m_free_teamates.pop_front();
    }   

    return 1;
}

std::string company::Manager::team_report()
{
    std::string report;
    report = m_name + " give to my team " + std::to_string(m_task) + " task\n";
    report += std::to_string(m_id) + "_team: \n";
    for (Worker& w : m_busy_teamates)
    {
        report += "\t" + w.job_report() + "\n";
    }
    return report;
}

company::Director::Director(std::string name, std::list<Manager> team)
{
    m_name = name;
    m_task = 0;
    m_free_teamates = team;
    
}

bool company::Manager::operator==(Manager m)
{
    if (m_id == m.m_id) return 1;
    return 0;
}

int company::Director::give_task()
{
    if (m_free_teamates.empty()) return 1;
    for (Manager& m : m_free_teamates)
    {
        std::cout << m.m_name << "\n";
        m.take_task(m_task);
        if (m.give_task() == 0) // manager have't free workers
        {
            m_busy_teamates.push_back(m);
            m_free_teamates.remove(m);           
        }
    }
    return 0;
}

std::string company::Director::team_report()
{
    std::string report;
    report += std::string(15,'-') + "\n";
    report += m_name + " task " + std::to_string(m_task) + "\n";
    for (Manager& m : m_busy_teamates)
    {
        report += m.team_report();
    } 
    return report;
}