#include <iostream>

#define saturday(a) ((a==7) ? "saturday" : "error")
#define friday(a) ((a==6) ? "friday" : saturday(a))
#define thursday(a) ((a==5) ? "thursday" : friday(a))
#define wenesday(a) ((a==4) ? "wenesday" : thursday(a))
#define tuesday(a) ((a==3) ? "tuesday" : wenesday(a))
#define monday(a) ((a==2) ? "monday" : tuesday(a))
#define sunday(a) ((a==1) ? "monday" : monday(a)) 


int main(int argc, char** argv)
{

    int a;
    std::cin >> a;
    std::cout << sunday(a);

    return 0;
}