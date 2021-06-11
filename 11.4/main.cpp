#include <iostream>
float freq_mass[10];
int main() {
    std::cout << "Setup radio frequencies: " << std::endl;
    for (int i=0;i<10;i++){
        std::cout << "  " << i+1 << " channel: ";
        std::cin >> freq_mass[i];
    }
    int channel_select = 1;
    while (bool(channel_select)){
        std::cout << "current channel: " << channel_select <<'(' << freq_mass[channel_select-1] << " f)" << std::endl;
        std::cout << "please choose new channel: ";
        std::cin >> channel_select;
        if ((channel_select<0)||(channel_select>sizeof(freq_mass)/sizeof(freq_mass[0]))){
            std::cout << "such channel did`t exist\n";
            channel_select  = 1;
        }
    }
    return 0;
}
