#ifndef EVAL_STRING_HPP
#define EVAL_STRING_HPP

#include <string>
#include <cstdint>
#include <unordered_map>
#include <stack>
#include "eval_char.hpp"
#include <fstream>
#include <filesystem>
#include "../utils.hpp"

namespace BF {
	void eval_string(const std::string &input, std::vector<uint8_t>::iterator &pointer, std::vector<uint8_t> &arr, std::unordered_map<std::string, std::string> &function_map, std::string location, const bool in_line = 0);
}

#endif