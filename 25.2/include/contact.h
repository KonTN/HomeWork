#pragma once 

#include <string>
#include <vector>
#include <set>

class Contact
{
    public:
        Contact(std::string _name);
        std::vector<std::string>  get_numbers();
        std::string get_name();
        void add_number(std::string);
        static bool is_phone_number(std::string number);
    private:
        std::set<long> numberList;
        std::string name;
        
};