#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int loadFileGroup(std::string FolderPath, std::vector<std::string> &FileDataContainer){

    std::ifstream file;
    int fileCounter = 0;
    while (true){
        file.open(FolderPath+std::to_string(fileCounter)+".txt");
        if (!file.is_open()) {
            break;
        }

        std::string buff;
        FileDataContainer.push_back("");
        while (getline(file,buff)) FileDataContainer[fileCounter] += buff + "\n";
        
        if (FileDataContainer[fileCounter].empty()) {
            return 1;
        }
        file.close();
        fileCounter ++;
    }
    return 0;
}

int main(int argc, char** argv){ 
    
    int questionCounter  =  0; // question total amount
    int answerCounter = 0; // anwers total amount 
    std::vector<std::string> questionList;
    std::vector<std::string> answerList;

    // load question list 
     if (loadFileGroup("questions/",questionList)) {
         std::cout << "Error: question file read error";
         return 1;
     }
    // load answers
    if (loadFileGroup("answers/",answerList)) {
         std::cout << "Error: answer file read error";
         return 1;
     }

    answerCounter = answerList.size();
    questionCounter = questionList.size();

    if (answerCounter == 0) {
        std::cout << "Error: can`t upload any questions from questions files";
        return 1;
    }

    if (answerCounter == questionCounter){
        std::cout << "successfully uploaded " << questionCounter << " questions" << std::endl;
    }
    else {
        std::cout << "Error: question and answer quantity don't match " << questionCounter << ' ' << answerCounter << std::endl;
        return 1;
    }


    // game loop
    int playersPoints = 0, vieversPoints = 0;
    int position = 0;

    bool questionPlayAbility[questionCounter+1]; // if question already played disable it playability
    for (bool &i : questionPlayAbility) i = true; // we can`t play played question twise

    while (!(playersPoints >= questionCounter/2+1 || vieversPoints >= questionCounter/2+1)){
        std::cout << "PLease enter ofset: ";
        int ofset;
        std::cin >> ofset;
        
        // fiend next question
        position += ofset;
        position %= questionCounter; // to not outrange question vector
        while (!questionPlayAbility[position]){
            position ++;
            position %= questionCounter;
        }

        //play question
        std:: cout << "Next question (" << position <<"): " << std::endl;
        std::cout << questionList[position];


        // get answer  
        std::cout << "Enter your answer (one word): ";
        std::string answer;
        std::cin >> answer;

        // check answer
        if (answer+'\n' == answerList[position]){
            playersPoints ++;
            std::cout << "Than was right answer! playees get one more point (" << playersPoints << ")" << std::endl;
        }
        else {
            vieversPoints ++;
            std::cout << "That was wrong answer! vievers get point (" << vieversPoints << ")" << std::endl;
        }

        questionPlayAbility[position] = false;        
    }

    std::cout << std:: endl;
    std::cout << "!!! Congratulation to " << (playersPoints > vieversPoints?"players":"viewers") << " they win with score - ";
    std::cout << vieversPoints << ":" << playersPoints  << " !!!"<< std::endl;

    return 0;
}