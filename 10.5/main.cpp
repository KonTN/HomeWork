#include <iostream>
#include  <vector>
std::vector<std::string> field;
bool try_to_find_winner(const std::vector<std::string> &gameFil){
    for (int i=0;i<3;i++){
        if (((gameFil[0][i] == gameFil[1][i])&&(gameFil[1][i] == gameFil[2][i]))&&(gameFil[0][i] != '.')) return true;
        if (((gameFil[i][0] == gameFil[i][1])&&(gameFil[i][1] == gameFil[i][2]))&&(gameFil[i][0] != '.')) return true;
    }

    if ((gameFil[0][0] == gameFil[1][1])&&(gameFil[1][1] == gameFil[2][2])&&(gameFil[0][0] != '.')) return true;
    if ((gameFil[0][2] == gameFil[1][1])&&(gameFil[1][1] == gameFil[2][0])&&(gameFil[0][2] != '.')) return true;
    return false;
}
bool validate_field(const std::vector<std::string> &gameFil) {
    int dotCounter = 0,xCounter = 0, oCounter = 0;
    for (const std::string &i : gameFil){
        for (const char j : i){
            if (j == '.') dotCounter ++;
            else if (j == 'X') xCounter ++;
            else if (j == 'O') oCounter ++;
        }
    }
    if (dotCounter+xCounter+oCounter!=9) return  false;
    if (abs(oCounter-xCounter)>1) return false;
    if (oCounter == xCounter) return false;
    return true;
}
char find_winner(const std::vector<std::string> &gameFil){
    int xCounter = 0,oCounter = 0;
    for (const std::string &i : gameFil){
        for (const  char j : i){
            if (j == 'X') xCounter ++;
            else if (j == 'O') oCounter ++;
        }
    }
    return ((xCounter>oCounter)?'X':'O');
}
int main() {
    std::string buff;
    for (int i=0;field.size()<3;i++){
        std::getline(std::cin,buff);
        if (!buff.empty()) field.push_back(buff);
    }
    if(try_to_find_winner(field)&&validate_field(field)) std::cout << find_winner(field) << " Won congratulation!";
    else std::cout << "can not calculate winner.";
    return 0;
}
