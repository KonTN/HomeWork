#include <iostream>



#define SUMMER 1
#define AUTUM 0
#define WINTER 0
#define SPRING 0



#if SUMMER
int main(int argc,char** argv)
{
    std::cout << "SUMMER";
    return 0;
}
#endif

#if AUTUM
int main(int argc,char** argv)
{
    std::cout << "AUTUM";
    return 0;
}
#endif

#if WINTER
int main(int argc,char** argv)
{
    std::cout << "WINTER";
    return 0;
}
#endif

#if SPRING
int main(int argc,char** argv)
{
    std::cout << "SUMMER";
    return 0;
}
#endif