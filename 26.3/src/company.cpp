#include "company.h"
#include <iostream>



company::Worker::Worker()
{
    myName = "empty_name";
    myJob = 'N';
};

company::Worker::Worker(std::string name)
{
    myName = name;
    myJob = 'N';
};

int company::Worker::set_job(char job)
{
    if ((job != 'A')&&(job != 'B')&&(job != 'C'))
    {
        std::cout << myName << ": received wrong job ( " << job << " )\n";
        return 1;
    }
    else 
    {
        myJob = job;
        std::cout << myName << " : received " << myJob << " job.\n";
        return 0;
    }

};

char company::Worker::get_job()
{
    return myJob;
};




company::Manager::Manager(std::string name, int id , std::vector<std::string> teamNames)
{
    myName = name;
    myId = id;
    for (std::string wName : teamNames)
    {
        myTeam.push_back(Worker(wName));
    }
    myJob = -1;
};

int company::Manager::set_job(int job)
{
    
}

