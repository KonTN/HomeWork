#include <iostream>
#include <list>
#include <map>


#include "swimmer.h"


#define  SWIMMERS_COUNTER 6

void timer(float& time)
{
    time += 0.01;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}


int main()
{
    std::list<Swimmer> swimmerPool;
    std::cout << "Please enter names and speeds of swimmers (example : Jon 10)\n";
    for (int i =0; i < SWIMMERS_COUNTER; i++)
    {
        std::string dummyName;
        int dummySpd;
        std::cout << i+1 << " swimmer:";
        std::cin >> dummyName >> dummySpd;
        Swimmer dummy(dummyName,dummySpd);
        swimmerPool.emplace_back(dummy);
    }

    // start race
    float time = 0;
    std::thread t(timer,std::ref(time));
    t.detach();
    for (Swimmer &s : swimmerPool)
    {
        s.start_swim();
    }

    std::map<std::string,float> finishedSwimmers;

    bool notEveryoneFinished = true;
    while (notEveryoneFinished)
    {

        std::cout << std::string (30, '#') << "\n";
        for (Swimmer &s : swimmerPool) {
            std::cout.width(10);
            std::cout << s.get_name() << " : " << std::string((int)s.get_floated_distance() / 5, '*');
            if (s.get_floated_distance() < 100) {
                std::cout << " " << s.get_floated_distance() << "/100m" << "\n";
            }
            else
            {
                if (finishedSwimmers.count(s.get_name()) == 0)
                {
                    finishedSwimmers[s.get_name()] = time;
                }
                std::cout << " finished!" << "\n";
            }
        }
        std::cout << std::string (30, '#') << "\n";

        // waiting for second
        time ++;
        std::this_thread::sleep_for(std::chrono::seconds (1));


        // is everyone finished
        notEveryoneFinished = finishedSwimmers.size() != SWIMMERS_COUNTER;
    }

    std::multimap<float,std::string> resoluteTable;
    for (auto &p : finishedSwimmers)
    {
        resoluteTable.insert(std::make_pair(p.second,p.first));
    }
    std::cout << "\nResolute table: \n";
    for (auto  &p : resoluteTable)
    {
        std::cout << "\t" <<  p.second << " : " << p.first-0.1 << " seconds\n";
    }
    return 0;
}