#include <iostream>
#include  <vector>
std::vector<std::string> field;

bool validate_field(const std::vector<std::string> &field,const char &winner){
    int dotCounter= 0,xCounter= 0,oCounter = 0;
    for (std::string line : field){
        if (line.size()!=3){
            return false;
        }
        for (char h:line){
           if (h=='.') dotCounter ++;
           if (h=='X') xCounter ++;
           if (h=='O') oCounter ++;
        }
    }
    if ((winner != 'X')&&(winner != 'O')) return false;
    if ((winner == 'X')&&(xCounter<=oCounter)) return false;
    if ((winner == 'O')&&(oCounter<=xCounter)) return false;
    if (abs(xCounter-oCounter)>1) return false;
    if (xCounter+oCounter+dotCounter!=9) return false;
    return true;
}

char calculate_winner(const std::vector<std::string> &field) {
    // size check
    if (field.size()<3) return '?';
    for (std::string line : field) if (line.size()<3) return '?';


    for (int i=0;i<3;i++){
        if ((field[i][0]==field[i][1]==field[i][2])&&(field[i][0]!='.')) return field[i][0]; // all lines
        if ((field[0][i]==field[1][i]==field[2][i])&&(field[0][i]!='.')) return field[i][0]; // all columns
    }

    // diagonals
    if ((field[0][0]==field[1][1]==field[2][2])&&(field[0][0]!='.')) return field[0][0];
    if ((field[2][0]==field[1][1]==field[0][2])&&(field[2][0]!='.')) return field[2][0];

    // return . if non won
    return '?';
}

int main() {
    std::string buff;
    for (int i=0;field.size()<3;i++){
        std::getline(std::cin,buff);
        if (!buff.empty()) field.push_back(buff);
    }
    char winner = calculate_winner(field);
    if ((validate_field(field,winner))&&((winner != 'X')&&(winner != 'O'))) std::cout << "impossible calculate the winner\n";
    else  std::cout << winner << " won, congratulations!";


    return 0;
}
