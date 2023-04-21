#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include "BF.h"

int main(int argc, char* argv[]){
    
    bool force_in_line=0;        
    for(int i=1;i<argc;i++){
        std::string arg = argv[i];
        std::transform(arg.begin(),arg.end(),arg.begin(), ::toupper);
        
        if (arg.length() > 1 && arg[0] == '-') {
            if(arg[1]=='?'||arg[1]=='H'){
                std::cout<<"-h|? help...\n-e enable readig inline \n-d disable reading inline \n-c read from console mode \n-f read from file mode \n-(Ctrl+D to stop a script and still get an output) \n";
            }
            if((arg[1]=='E')&&force_in_line==0){
                force_in_line=1;
                BF::in_line=1;
            }
            if((arg[1]=='D')&&force_in_line==0){
                force_in_line=1;
                BF::in_line=0;
            }
            if(arg[1]=='F'){
                    if(i+1>=argc){
                    std::cerr<<"No file path specified!"<<std::endl;
                    return 0;
                }
                if(!force_in_line){
                    BF::in_line=0;
                }
                BF::evalFile(argv[i+1]);
                return 0;
            }
            if(arg[1]=='C'){
                if(!force_in_line){
                    BF::in_line=1;
                }
                BF::startInterpretor();
                return 0;
            }
        }
    }
}
