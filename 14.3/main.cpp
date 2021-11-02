#include <iostream>
#include <set>


int main(){
    std::set<int> num;
    int buff;
    do{
        do{
        std::cin >> buff;
        num.insert(buff);
        } while ((buff!=-1)||(buff!=-2));
        // dump way to do that -----------
        int i=0;
        int value;
        for(int i: num){
            i++;
            if (i==5) {value = i; break;}
        }
        //--------------------------------
        system("cls");
        std::cout<< value << std::endl;
        system("pause");
    }while (buff!=-2);
    return 0;
}