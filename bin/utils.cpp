#include "utils.hpp"

std::string BF::find_parent(const std::string &path) {
	std::size_t last_slash = path.rfind('/');
	if (last_slash == std::string::npos) {
		return std::string();
	}
	return path.substr(0, last_slash);
}