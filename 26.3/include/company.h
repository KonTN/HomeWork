#pragma once
#include <string>
#include <vector>

namespace company
{
    

    class Worker
    {
        public:
            Worker();
            Worker(std::string name);
            int set_job(char job);
            char get_job();
        private:
            std::string myName;
            char myJob;
    };


    class Manager : public Worker
    {
        public:
            Manager(std::string name, int id, std::vector<std::string> teamNames);
            int set_job(int job);
        private:
            int myId;
            std::string myName;
            int myJob;
            std::vector<Worker> myTeam;
    };

    class Principal : public Manager
    {
        public:
            Principal(std::string name, std::vector<std::string> teamNames);
            int set_job(int job);
        private:
            std::string myName;
            int myJob;
            std::vector<Manager> myTeam;
    };
}