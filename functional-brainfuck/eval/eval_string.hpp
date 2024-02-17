#ifndef EVAL_STRING_FBF_HPP
#define EVAL_STRING_FBF_HPP

#include <string>
#include <cstdint>
#include <unordered_map>
#include <stack>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
//#include "eval_char.hpp"
#include "../string_utils.hpp"
#include "../flags.hpp"

namespace FBF {
	void eval_string(const std::string &input, std::vector<uint8_t>::iterator &pointer, std::vector<uint8_t> &arr, std::unordered_map<std::string, std::string> &function_map, const std::string &location, const std::string &log_path, const int flags);
}

#endif