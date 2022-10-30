#include <iostream>
#include <vector>

#include "company.h"



int main(int, char**) {
    std::cout << "################################\n";
    std::cout << "Please enter teams amount: ";
    int teamsAmount;
    std::cin >> teamsAmount;

    std::vector<company::Manager> teams;
    for (int i = 0; i < teamsAmount; i++)
    {
        
        std::cout << "\tPlease enter number of workers in " << i+1 <<" team: ";
        int workers;
        std::cin >> workers;

        std::vector<company::Worker> team;
        for (int j = 0; j < workers; j++)
        {
            std::string worker_name = "worker_"+std::to_string(j+1);
            company::Worker w(worker_name);
            team.push_back(w);
        }

        std::string manager_name = "manager_"+std::to_string(i+1);
        company::Manager m(manager_name, i,team);
        teams.push_back(m);
    }
    

    company::Director director("Drector",teams);
    
    std::cout << "################################\n";
    
    int newJob;
    bool done;
    do {
        std::cout << "\nPlease enter new job number: ";
        std::cin >> newJob;
        done = director.give_job(newJob);
    } while (done);
    
    std::cout << "################################\n";
    return 0;
}
