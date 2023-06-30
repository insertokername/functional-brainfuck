#include "string_utils.hpp"

std::string FBF::find_parent(const std::string &path) {
	std::size_t last_slash = path.rfind('/');
	if (last_slash == std::string::npos) {
		return std::string();
	}
	return path.substr(0, last_slash);
}

std::string FBF::make_valid_path(std::string in) {
	std::transform(in.begin(), in.end(), in.begin(), [](char c) {if (c == '\\') { return '/'; } else return c; });
	return in;
}