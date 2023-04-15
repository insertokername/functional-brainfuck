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
            case '.':
                std::cout<<(*pointer);
                break; 
        } 
    }
    if(!loopStack.empty()){
        std::cerr<<"Unclosed paranthases!\n";
        exit(1);
    }
}

void evalFile(char path[]){
        
    std::ifstream inputFile(path);
    
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        exit(1);
    }
    
    std::string input( (std::istreambuf_iterator<char>(inputFile) ),
                       (std::istreambuf_iterator<char>()    ) );

    evalString(input);
}

void startInterpretor(){
    std::string input;
    while(true){
        std::cin>>input;
        evalString(input);
    }
}

int main(int argc, char* argv[]){
    for(int i=1;i<argc;i++){        
        std::string arg = argv[i];
        if (arg.length() > 1 && arg[0] == '-') {
            if(arg[i]=='h'&&arg[i]=='H'){
                std::cout<<"h-";
            }
            if(arg[1]=='l'&&arg[i]=='L'){

            }
            if(arg[1]=='f'&&arg[i]=='F'){
                    if(i+1>=argc){
                    std::cerr<<"No file path specified!";
                    return 0;
                }
                evalFile(argv[i+1]);
                return 0;
            }
            if(arg[1]=='i'&&arg[i]=='I'){
                startInterpretor();
                return 0;
            }
        }
    }
}
