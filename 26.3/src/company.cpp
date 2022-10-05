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
        std::cout << "\t" << myName << ": received wrong job ( " << job << " )\n";
        return 1;
    }
    else 
    {
        myJob = job;
        std::cout << "\t" << myName << " : received " << myJob << " job.\n";
        return 0;
    }

};

char company::Worker::get_job()
{
    return myJob;
};


company::Manager::Manager()
{
    myName = "UNKNOWN";
    myId = -1;
    myTeam.clear();
    freeTeamatesCouter = -1;
};

company::Manager::Manager(std::string name, int id , std::vector<std::string> teamNames)
{
    myName = name;
    myId = id;
    for (std::string wName : teamNames)
    {
        myTeam.push_back(Worker(wName));
    }
    freeTeamatesCouter = myTeam.size();
};

bool company::Manager::has_free_worker()
{
    for (Worker w : myTeam)
    {
        if (w.get_job() == 'N') return 1;
        
    }
    return 0;
}

int company::Manager::set_job(int job)
{   
    std::srand(job+myId);
    int jobCount = rand()%(myTeam.size()+1);
    if (jobCount > freeTeamatesCouter) jobCount = freeTeamatesCouter;

    std::cout << "\n"<< myName << " received " << job <<" job.\n";
    std::cout << "give team_" << myId+1 << " " << jobCount << " jobs.\n";
    for (Worker& w : myTeam)
    {
        if (freeTeamatesCouter <= 0) 
        {
            std::cout << "team_" << myId+1 << " have`t free workers\n";
            return -1;
        }

        if (jobCount == 0) return 0;
        
        if (w.get_job() == 'N') // if worker has no job
        {
            w.set_job(65+rand()%3);
            jobCount --;
            freeTeamatesCouter --;
            
        }

        if (freeTeamatesCouter <= 0) 
        {
            std::cout << "team_" << myId+1 << " have`t free workers\n";
            return -1;
        }
        
    }
    return 1;
};

company::Principal::Principal(std::string name, std::vector<int> workersInTeamsAmount)
{
    myName = name;
    for (int i = 0; i < workersInTeamsAmount.size(); i++)
    {
        std::string mName = "Tom_" + std::to_string(i+1);
        std::vector<std::string> wNames;
        for (int j = 0; j < workersInTeamsAmount[i]; j++)
        {
            wNames.push_back("Bob_" + std::to_string(j));
        }
        myTeam.push_back(Manager(mName,i,wNames));
    }
    freeTeamatesCouter = myTeam.size();
};

int company::Principal::set_job(int job)
{ 
   std::cout << myName << " give managers " << job << " job.\n\n";

    for (Manager& m : myTeam)
    {
        if (m.has_free_worker() == 0) // teams has't free workers
        {
            freeTeamatesCouter --;
        }
        else
        {
            m.set_job(job);
        }

        if (freeTeamatesCouter == 0) 
        {
            std::cout << "\nAll workers has a job\n";
            return -1;
        }
    }
    std::cout << "-------------------------------------------------------------\n";
    return 1;
}