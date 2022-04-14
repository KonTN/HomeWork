#include <iostream>
#include <map>

std::map<char,int> countChars(const std::string& str)
{
    std::map<char,int> charMap;
    for (char c : str)
    {
        charMap[c] ++;
    }
    return charMap;
}

int main(int argc, char** argv)
{
    std::map <char,int> fLineMap, sLineMap;
    std::string fLine, sLine;
    
    std::cout << "Enter firs line: ";
    getline(std::cin,fLine);
    fLineMap = countChars(fLine);

    std::cout << "Enter second line: ";
    getline(std::cin,sLine);
    sLineMap = countChars(sLine);

    std::cout << ((fLineMap == sLineMap)?"Yes, you can":"No, just no") << std::endl;

    return 0;
}