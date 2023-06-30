#ifndef BF_UTILS_HPP
#define FBF_UTILS_HPP

#include <string>
#include <algorithm>

namespace FBF {
	std::string find_parent(const std::string &path);
	std::string make_valid_path(std::string in);
}
#endif