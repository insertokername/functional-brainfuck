#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <cstdlib>

constexpr std::size_t SIZE = 30000;
uint8_t arr[SIZE];
uint8_t* pointer=arr;
int skippingLoop=0;
std::stack<std::size_t> loopStack;

void evalChar(const char input){
    switch (input){
    case '>':
        if(pointer-arr==SIZE-1){
            pointer=arr;
        }
        else{
        pointer++;
        }
        break;
    case '<':
        if(pointer-arr==0){
            pointer=arr+SIZE-1;
        }
        else{
        pointer--;
        }
        break;
    case '+':
        (*pointer)++;
        break;
    case '-':
        (*pointer)--;
        break;
    case '.':
        std::cout<<(*pointer);
        break;
    case ',':
        std::cin>>(*pointer);
        break;
    case 'q':
        exit(0);
        break;
    case 'Q':
        exit(0);
        break;
    }
}

void evalString(std::string& input){
    for(std::size_t i=0;i<input.size();i++){
        if(!skippingLoop){
            evalChar(input[i]);
        }

        switch (input[i]){
            case '[':
                loopStack.push(i);
                if((*pointer)==0){
                    skippingLoop++;
                }
                break;
            case ']':
                if(skippingLoop){
                    loopStack.pop();
                    skippingLoop--;
                }
                else{
                    if((*pointer)==0){
                        loopStack.pop();
                    }else{
                        i=loopStack.top();
                    }
                }
                break  ;   
        } 
    }
    if(!loopStack.empty()){
        std::cerr<<"Unclosed paranthases!\n";
        exit(1);
    }
}

void evalFile(std::string& path){
        
    std::ifstream inputFile(path);
    
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        exit(1);
    }
    
    std::string input( (std::istreambuf_iterator<char>(inputFile) ),
                       (std::istreambuf_iterator<char>()    ) );

    evalString(input);
}

int main(int argc, char* argv[]){

    

    if(argc==3&&(argv[2]=="-f"||argv[2]=="-F")){

    }
    else{
        std::string input;
        while(true){
            std::cin>>input;
            evalString(input);
        }
    }
}
