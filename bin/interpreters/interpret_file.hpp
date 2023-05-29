#ifndef EVAL_FILE_BF_HPP
#define EVAL_FILE_BF_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include "../utils.hpp"
#include "../eval/eval_string.hpp"


namespace BF {
	void interpret_file(const std::string &path, bool in_line);
}

#endif