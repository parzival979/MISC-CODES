#include <iostream>
#include <vector>


class words{
public:
    std::vector<std::string> arrayWords;
    bool compareWords(std::string word1,std::string word2);
    void swapWords(std::string &word1,std::string &word2){
        std::string temp;
        temp=word2;
        word2=word1;
        word1=temp;
    };
    void sortWords();
    void printVector(){
        for (int i = 0; i < arrayWords.size(); ++i) {
            std::cout<<arrayWords[i]<<"\n";
        }
    };

};

//returns true if first word greater than second one
bool words::compareWords(std::string word1, std::string word2){
    for (int i = 0; i < word1.size() && i<word2.size(); ++i) {
        if(word1[i]<word2[i])
            return true;
        else if(word1[i]>word2[i])
            return false;
        else
            continue;
    }

    if(word1.size()<word2.size()){
        return true;
    }
    else{
        return false;
    }


}

void words::sortWords(){
    for (int i = 0; i < arrayWords.size()-1; ++i) {
        for (int j = 0; j < arrayWords.size() -1 - i; ++j) {
            if(!compareWords(arrayWords[j],arrayWords[j+1]))
                swapWords(arrayWords[j],arrayWords[j+1]);
        }
    }
}



int main(void){
    words reqObject;
    while(true){
        int menuOption;
        std::cout<<"ENTER 1 TO ENTER A WORD ELSE 0 TO STOP\n";
        std::cin>>menuOption;
        if(menuOption==1){
            std::cout<<"PLEASE ENTER A WORD WITHOUT CAPITAL LETTERS\n";
            std::string temp;
            std::cin>>temp;
            reqObject.arrayWords.push_back(temp);
        }
        else if(menuOption==0){
            break;
        }
        else{
            std::cout<<"PLEASE CHOOSE THE CORRECT OPTION\n";
        }
    }
    std::cout<<"THE ENTERED LIST OF WORDS IS\n";
    reqObject.printVector();
    reqObject.sortWords();
    std::cout<<"THE SORTED LIST OF WORDS IS\n";
    reqObject.printVector();



}