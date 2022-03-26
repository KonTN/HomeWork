#include <iostream>
#include <fstream>
#include <ctime>

enum banknoteTypes {
    HUNDREED = 0,
    TWO_HUNDREED,
    FIVE_HUNDREED,
    THOUSAND,
    TWO_THOUSAND,
    FIVE_THOUSAND
};

int  banknoteSubtrection(int &summ, int &banknoteAmount,const int banknoteType){
    int moneyCounter = 0;
    while(summ >= banknoteType){
            if (banknoteAmount>0) {
                summ -= banknoteType;
                banknoteAmount --;
                moneyCounter += banknoteType;
            }
            else {
                break;
            }
        }
    return moneyCounter;
}

void fillAtmFile(std::ofstream& atmFile,int num){
    switch (num)
    {
    case HUNDREED:
        atmFile << '0';
        break;
    case TWO_HUNDREED:
        atmFile << '1';
        break;
    case FIVE_HUNDREED:
        atmFile << '2';
        break;
    case THOUSAND:
        atmFile << '3';
        break;
    case TWO_THOUSAND:
        atmFile << '4';
        break;
    case FIVE_THOUSAND:
        atmFile << '5';
        break;
    }
}

int main(int argv, char** argc){

    std::cout << "Please choose mode ('+' - update '-' - withdraw): ";
    char mode;
    std::cin >> mode;

    if ((mode != '+')&&(mode != '-')){
        std::cout << "Error: wrong mode";
        return 1;
    }

    // fiil atm
    if (mode == '+'){
        std::ofstream atmFile;
        atmFile.open("atm.txt",std::ios::binary);
        std::srand(std::time(nullptr)); // to get diffrent random sead
        
        for (int i = 0; i<1000;i++){        
            int banknoteType = rand()%6;
            fillAtmFile(atmFile,banknoteType);
        }
        
        atmFile.close();
    }

    // withdraw money
    if (mode == '-'){
        std::ifstream atmFileInputStream;
        atmFileInputStream.open("atm.txt",std::ios::binary);

        //parse banknote ammount from file
        int banknoteAmount[6] = {0,0,0,0,0,0};
        char buff[1];
        int counter = 0;
        while(!atmFileInputStream.eof()){
            atmFileInputStream.read(buff,sizeof(buff));
            buff[atmFileInputStream.gcount()] = 0;
            if ((buff[0] < '7')&&(buff[0] >= '0')){
                 banknoteAmount[buff[0] -'0'] ++;
                 counter ++;
            }
        }
        atmFileInputStream.close();
        std::cout << "Total bacnknote amount " << counter << std::endl;

        //get summ
        std::cout << "Please enter the summ(divisible by 100): ";
        int summ;
        std::cin >> summ;
        summ/=100;
        summ*=100;
        if (summ <= 0){
            std::cout << "Error: wrong summ";
            return 1;
        }

        // issue cash
        int totalEXtradition = 0;
        totalEXtradition += banknoteSubtrection(summ,banknoteAmount[FIVE_THOUSAND],5000);
        totalEXtradition += banknoteSubtrection(summ,banknoteAmount[TWO_THOUSAND],2000);
        totalEXtradition += banknoteSubtrection(summ,banknoteAmount[THOUSAND],1000);
        totalEXtradition += banknoteSubtrection(summ,banknoteAmount[FIVE_HUNDREED],500);
        totalEXtradition += banknoteSubtrection(summ,banknoteAmount[TWO_HUNDREED],200);
        totalEXtradition += banknoteSubtrection(summ,banknoteAmount[HUNDREED],100);

        if (summ != 0 ){
            std::cout << "Can not issue such summ " << summ << " will be left" << std::endl;
        }
        std::cout << totalEXtradition  << " money was issued" << std::endl;

        // write remains back to the atm file    
        std::ofstream atmFileOutputStream;
        atmFileOutputStream.open("atm.txt",std::ios::binary);

        for (int i = 0;i <= 6;i++){
            for (int j=0;j<banknoteAmount[i];j++){
                fillAtmFile(atmFileOutputStream,i);
            }
        }
        atmFileOutputStream.close();    
    }

    return 0;
}