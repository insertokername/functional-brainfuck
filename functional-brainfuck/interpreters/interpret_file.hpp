#ifndef EVAL_FILE_FBF_HPP
#define EVAL_FILE_FBF_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include "../flags.hpp"
#include "../string_utils.hpp"
#include "../eval/eval_string.hpp"


namespace FBF {
	void interpret_file(const std::string &path, int flags);
}

#endif