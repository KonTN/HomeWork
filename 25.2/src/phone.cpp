#include "phone.h"

Phone::Phone()
{
    Contact emptyCon("");
    phoneBook.push_back(emptyCon);
    
}

Phone::~Phone()
{

}

void Phone::add_contact(std::string name, std::string number)
{
    for (Contact &c : phoneBook)
    {
        if (c.get_name() == name)
        {
            c.add_number(number);   
            break;;
        }    
    } 
    Contact dummyCon(name);
    dummyCon.add_number(number); 
    phoneBook.push_back(dummyCon);

};

Contact Phone::get_contact(std::string seachRequest)
{
    for (Contact &c : phoneBook)
    {
        // define search Request as name or as number
        if (Contact::is_phone_number(seachRequest))
        {
            for (std::string s : c.get_numbers())
            {
                if (s == seachRequest) return c;
            }
        }
        else 
        {
            if (c.get_name() == seachRequest) return c;
        }
    }

    Contact dummyCon("");
    return dummyCon;
}