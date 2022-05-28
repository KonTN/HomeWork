#pragma once


#include <vector>
#include "contact.h"

class Phone
{
    public:
        Phone();
        Contact get_contact(std::string searchRequest); 
        void add_contact(std::string name, std::string number);
        ~Phone();    
    private:
        std::vector<Contact> phoneBook;
};
