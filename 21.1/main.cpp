#include <iostream>
#include <map>

std::string int_to_phone(int number)
{
    std::string numberS = std::to_string(number);
    std::string phone = "";

    if (numberS.size()!=6) return "";
    
    for (int i=0;i<6;i++){
        if ((i%2==0)&&(i!=0)) phone.push_back('-');
        phone.push_back(numberS[i]);
    }

    return phone;
}

int parse_phone(std::string phone)
{
    if (phone.size()!=8) return 0;

    phone.erase(phone.begin() + 2);
    phone.erase(phone.begin() + 4);

    for (char c : phone){
        if ((c < '0')||(c > '9')) return 0;
    }
    return std::stoi(phone);
}

int main(int argc, char** argv)
{
    std::map<int,std::string> phoneBook;

    std::cout << "Command list: " << std::endl;
    std::cout << "  'q' - to quit program" << std::endl;
    std::cout << "  enter phone number to get last names (00-00-00)" << std::endl;
    std::cout << "  enter last name to phone number (Golovin)" << std::endl;
    std::cout << "  phone number and last name to add contact to phonebook (00-00-00 Golovin)" << std::endl;
    std::cout << std::endl;

    std::string command;

    bool quit = false;
    while (!quit)
    {
        std::cout << "Enter your command: ";
        getline(std::cin, command);
        if (command.find(' ')!=std::string::npos)
        {
            std::string phone = command.substr(0,command.find(' '));
            command.erase(0,command.find(' ')+1);
            std::string lastName = command;
            phoneBook.insert(std::make_pair(parse_phone(phone),lastName));
            continue;
        }
        
        if (command == "q") quit = true;
        else
        {
            int num = parse_phone(command);
            if (num) // if command str is valid phone number 
            {
                std::cout << phoneBook[num] << std::endl;
            }
            else // command is last name
            {
                for (auto pr : phoneBook)
                {
                    if (pr.second == command) std::cout << int_to_phone(pr.first) << std::endl;
                }
            }
        }
    }

    return 0;
}