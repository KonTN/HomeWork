#include "contact.h"

#include <sstream>



Contact::Contact(std::string _name)
{
    name  = _name;
}

std::string Contact::get_name()
{
    return name;
}

std::vector<std::string> Contact::get_numbers()
{
    std::vector<std::string> retSet;
    for (long l : numberList)
    {
        std::string dummyStr = "+7" + std::to_string(l);
        retSet.push_back(dummyStr);
    }

    return retSet;
}

bool Contact::is_phone_number(std::string number)
{
    // right phone number pattern : "+70000000000"
    if (number.size() != 12) return 0;
    if (number.substr(0,2) != "+7") return 0;
    for (char c : number.substr(3,number.size()))
    {
        if ((c < '0')||(c>'9')) return 0;
    }
    return 1;
}

void Contact::add_number(std::string number)
{
    if (is_phone_number(number))
    {
        long dummy = stol(number.substr(2,number.size()));
        numberList.insert(dummy);
    }
}