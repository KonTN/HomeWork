#include <iostream>
#include <string>
#include <map>

int main(int argc, char ** argv)
{
    std::map<std::string,int> queue;

    std::string command;
    while (1)
    {
        std::cin >> command;
        if (command == "next")
        {
            std::cout << queue.begin()->first << std::endl;
            queue.begin()->second --;
            if (queue.begin()->second <= 0) queue.erase(queue.begin());
            continue;
        }

        queue[command] ++;
        
    } 

    return 0;
}