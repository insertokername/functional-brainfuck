#ifndef BF_FUNCTION_FILE
#define BF_FUNCTION_FILE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

namespace BF{
    void init_line(bool _in_line);
    void evalChar(const char input);
    void evalString(std::string& input);
    void evalFile(char path[]);
    void startInterpretor();
}

#endif
