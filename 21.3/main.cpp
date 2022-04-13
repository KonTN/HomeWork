#include <iostream>
#include <map>



int main(int argc, char** argv)
{
    std::map <char,int> fLineMap, sLineMap;
    std::string fLine, sLine;
    
    std::cout << "Enter firs line: ";
    getline(std::cin,fLine);
    for (char c : fLine)
    {
        fLineMap[c] ++;
    }

    std::cout << "Enter second line: ";
    getline(std::cin,sLine);
    for (char c : sLine)
    {
        sLineMap[c] ++;
    }

    std::cout << ((fLineMap == sLineMap)?"Yes, you can":"No, just no") << std::endl;

    return 0;
}