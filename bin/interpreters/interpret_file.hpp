#ifndef EVAL_FILE_BF_HPP
#define EVAL_FILE_BF_HPP

#include <fstream>
#include <iostream>
#include <string>
#include "../eval/eval_string.hpp"


namespace BF {
	void interpret_file(char path[], bool in_line);
}

#endif