#ifndef EVAL_CHAR_BF_HPP
#define EVAL_CHAR_BF_HPP

#include <string>
#include <cstdint>
#include <vector>
#include <iostream>

namespace BF {
	void evalChar(const char input, std::vector<uint8_t>::iterator& pointer, std::vector<uint8_t>& arr);
}
#endif