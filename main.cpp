#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cstdlib>

constexpr std::size_t SIZE = 30000;
uint8_t arr[SIZE];
uint8_t* pointer=arr;
int skipping_loop=0;
bool in_line=0;
std::stack<std::size_t> loop_stack;

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
    case 'q':
        exit(0);
        break;
    case 'Q':
        exit(0);
        break;
    case '.':
        std::cout<<(*pointer)<<'\n';
        break; 
    }
}

void evalString(std::string& input){
    for(std::size_t i=0;i<input.size();i++){
        if(!skipping_loop){
            evalChar(input[i]);
        }

        switch (input[i]){ //i'm splitting the cases because i need to check if i should stop skipping characters 
            case '[':      //still to lazy to think of a better way to implement loops sry
                loop_stack.push(i);
                if((*pointer)==0){
                    skipping_loop++;
                }
                break;
            case ']':
                if(skipping_loop){
                    loop_stack.pop();
                    skipping_loop--;
                }
                else{
                    if((*pointer)==0){
                        loop_stack.pop();
                    }else{
                        i=loop_stack.top();
                    }
                }
                break;
            case ',':
                if(in_line){
                    if(i+1<input.size()){
                    i++;
                    (*pointer)=input[i];
                    }
                else{
                    std::cin>>(*pointer);
                }
                }
                else{
                std::cin>>(*pointer);
                }
                break;
        } 
    }
    if(!loop_stack.empty()){
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
        std::cout<<">>>";
        std::cin>>input;
        evalString(input);
    }
}

int main(int argc, char* argv[]){
    
    bool force_in_line=0;        
    for(int i=1;i<argc;i++){
        std::string arg = argv[i];
        if (arg.length() > 1 && arg[0] == '-') {
            if(arg[1]=='h'||arg[1]=='H'){
                std::cout<<"-h help?\n-e enable readig inline \n-d disable reading inline \n-c read from console mode \n-f read from file mode\n";
            }
            if((arg[1]=='e'||arg[1]=='E')&&force_in_line==0){
                force_in_line=1;
                in_line=1;
            }
            if((arg[1]=='d'||arg[1]=='D')&&force_in_line==0){
                force_in_line=1;
                in_line=0;
            }
            if(arg[1]=='f'||arg[1]=='F'){
                    if(i+1>=argc){
                    std::cerr<<"No file path specified!";
                    return 0;
                }
                if(!force_in_line){
                    in_line=0;
                }
                evalFile(argv[i+1]);
                return 0;
            }
            if(arg[1]=='c'||arg[1]=='C'){
                if(!force_in_line){
                    in_line=1;
                }
                startInterpretor();
                return 0;
            }
        }
    }
}
