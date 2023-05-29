#ifndef EVAL_CHAR_FBF_HPP
#define EVAL_CHAR_FBF_HPP

#include <string>
#include <cstdint>
#include <vector>
#include <iostream>

namespace FBF {
	void eval_char(const char input, std::vector<uint8_t>::iterator &pointer, std::vector<uint8_t> &arr);
}
#endif