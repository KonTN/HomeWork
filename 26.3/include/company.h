#pragma once
#include <string>
#include <list>
#include <vector>

namespace company
{
    class Worker
    {
        public:
            Worker();
            Worker(std::string name);
            void take_job(char job);
            bool free_job_check();
        protected:
            std::string m_name;
            char m_job;    
    };

    class Manager : Worker
    {
        public:
            Manager(std::string name, int id, std::vector<Worker> team);
            int give_job(int task);
            bool operator ==(Manager m);
        private:
            int m_id;
            int m_free_team_size;
            std::vector<Worker> m_team;
    };

    class Director : public Worker
    {
        public:
            Director(std::string name, std::vector<Manager> team);
            int give_job(int task); 
            static bool find_in_vec(std::vector<Manager> v, Manager fm);
        private:
            std::vector<Manager> m_team;
            std::vector<Manager> m_busy_team;
    };
}