#include <iostream>
#include <sstream>


int main(int argc, char** argv){
    enum switches{
        SOKET_POWER = 2,
        INNER_LIGHT = 4,
        OUT_LIGHT = 8,
        HOUSE_HEATING = 16,
        OUTPIPE_HEATING = 32,
        CONDITIONER = 64,
        LIGHT = 128
    };
    bool motionSens,lightSens;
    int innerTemp,outTemp;
    int time = 0;  
    int state = 0;

    while (1){
        std::cout << "time - " << time << ":00 Please enter sensor values(outTemp innerTemp motionSens lightSens): " << std::endl << std::endl;
        std::string parsedStr;
        std::getline(std::cin,parsedStr);

        std::stringstream parsedStream;        
        parsedStream << parsedStr;
        parsedStream >> outTemp >> innerTemp;
        
        // parsing sensors state
        parsedStr.clear();
        parsedStream >> parsedStr;
        motionSens = parsedStr=="yes";
        parsedStr.clear();
        parsedStream >> parsedStr;
        lightSens = parsedStr=="on";
        
        std::cout << std::endl << std::endl;

        if (outTemp < 0){
            if (!(state & OUTPIPE_HEATING)) std::cout << "outpipe heating:    on" << std::endl;
            state |= OUTPIPE_HEATING;
        }
        if (outTemp > 5){
            if (state & OUTPIPE_HEATING) std::cout << "outpipe heating:    off" << std::endl;
            state &= ~OUTPIPE_HEATING;
        }
        if (((time <5)||(time > 16))&motionSens){
            if (!(state & OUT_LIGHT)) std::cout << "out light:    on" << std::endl;
            state |= OUT_LIGHT;
        }
        else{
            if (state & OUT_LIGHT) std::cout << "out light:    off" << std::endl;
            state &= ~OUT_LIGHT;    
        }
        if (innerTemp < 22){
            if (!(state & HOUSE_HEATING)) std::cout << "heating:    on" << std::endl;
            state |= HOUSE_HEATING;
        }
        if (innerTemp > 25){
            if (state & HOUSE_HEATING) std::cout << "heating:    off" << std::endl;
            state &= ~HOUSE_HEATING;
        }
        if (innerTemp >= 30){
            if (!(state & CONDITIONER)) std::cout << "conditioner:    on" << std::endl;
            state |= CONDITIONER;
        }
        if (innerTemp <=25){
            if (state & CONDITIONER) std::cout << "conditioner:    off" << std::endl;
            state &= ~CONDITIONER;
        }
        if (lightSens){
            if (!(state & LIGHT)) std::cout << "light:    on" << std::endl;
            state |= LIGHT;
        }
        else{
            if (state & LIGHT) std::cout << "light:    off" << std::endl;
            state &= ~LIGHT;
        
        }
        if (state & LIGHT){
            int lightTemp;
            lightTemp = (time-16)*2200;
            if (lightTemp<5000) lightTemp = 5000;
            if (lightTemp>27000) lightTemp = 27000;
            std::cout << "  light temp = " << lightTemp << std::endl;
        }
        time ++;
        if (time >24) time = 0; 
        std::cout << std::endl <<std::endl;
    }

    return 0;
}