#include <iostream>
#include <sstream>

#include "contact.h"
#include "phone.h"


std::vector<std::string> parse_command(std::string str)
{
    std::stringstream retStm;
    std::vector<std::string> retVec;

    retStm << str;
    std::string word;
    while(!retStm.eof())
    {
        retStm >> word;
        retVec.push_back(word);
    }

    return retVec;
};


int main(int argc, char** argv)
{
    Phone* phone = new Phone();


    std::cout << "...................................\n";
    std::cout << "            Phone sim\n";
    std::cout << "...................................\n";
    std::cout << "Command list: \n";
    std::cout << "\tadd 'name' '+70000000000' - to add phone number to the contact list\n";
    std::cout << "\tcall 'name' or '+70000000000' - to call fiend phone\n";
    std::cout << "\tsms 'name' or '+70000000000' - to sms fiend phone\n"; 
    std::cout << "\texit - to close programm\n";
    std::cout << "...................................\n";
    std::cout << "Enter your command: \n";

    std::string command;

    do
    {
        std::getline(std::cin,command);
        // parse command 
        std::vector<std::string> args = parse_command(command);
        
        if ((args.front() == "add")&&(args.size() == 3)) // {'add', 'name', '+7000.....'}
        {
            std::string name = args[1];
            std::string number = args[2];
           
            if (Contact::is_phone_number(number))
            {
                phone->add_contact(name,number);
                std::cout << "Add new phone to your phone book\n";
            }
            else 
                std::cout << "Error: wrong phone format";
           
            continue;
        }
        if (((args.front() == "call")||(args.front() == "sms"))&&(args.size() == 2)) // {'command', 'name' or '+70000000...'} 
        {
            std::string searchRequest = args[1];

            Contact foundCon = phone->get_contact(searchRequest);
            if (!foundCon.get_name().empty()) // if we found contact with searchRequest;
            {
                if (args.front() == "sms")
                {
                    std::cout << "Please enter your massage: ";
                    std::string text;
                    std::getline(std::cin,text);
                } 

                if ((Contact::is_phone_number(searchRequest))
                    ||((!Contact::is_phone_number(searchRequest))&&(foundCon.get_numbers().size()==1))) 
                    // if contact number determined 
                    //(we searched thrue numbers or we searched thrue names and contact has only one number)
                {
                    std::cout <<( (args.front() == "call")?"Calling ":"SMS to "); 
                    std::cout << foundCon.get_name() << " " << foundCon.get_numbers().front() << std::endl;
                }
                else 
                {
                    int i = 0;
                    for (std::string num : foundCon.get_numbers())
                    {
                        i++;
                        std::cout << i << '\t' << num << std::endl;
                    }
                    std::cout << "Please chouse phone to ";
                    std::cout << ((args.front() == "call")?"call : ":"send SMS : "); 

                    int choice;
                    std::cin >> choice;
                    if (choice <=0) choice = 1;
                    if (choice >= foundCon.get_numbers().size()) choice = foundCon.get_numbers().size()-1;
                    std::cout << ((args.front() == "call")?"Calling ":"SMS to "); 
                    std::cout << foundCon.get_name() << " " << foundCon.get_numbers()[choice-1] << std::endl;
                }
            }
            else
            {
                std::cout << "Can't find any" << searchRequest << " contact" << std::endl;
            }
            continue;
        }   
        if (args.front() == "exit") continue;

        std::cout << "unknown command!\n";

    } while (command != "exit");
    
    delete phone;
    return 0;
}