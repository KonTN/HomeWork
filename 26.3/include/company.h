#pragma once
#include <string>
#include <list>

namespace company
{
    class Worker
    {
        public:
            Worker();
            Worker(std::string name);
            void take_task(int task);
            bool empty_task_check();
            std::string job_report();
        private:
            std::string m_name;
            int  m_task;
    };

    class Manager : public Worker
    {
        public:
            Manager();
            Manager(std::string name, int id , std::list<Worker> team);
            void free_team();
            int give_task();
            std::string team_report();
            bool operator == (Manager m);
            std::string m_name;
        private:
            
            int m_id;
            int m_task;
            std::list<Worker> m_free_teamates;
            std::list<Worker> m_busy_teamates;
    };

    class Director : public Manager 
    {
        public:
            Director(std::string name, std::list<Manager> team);
            int give_task();
            std::string team_report();
        private:
            std::string m_name;
            int m_task;
            std::list<Manager> m_free_teamates;
            std::list<Manager> m_busy_teamates;
    };
}