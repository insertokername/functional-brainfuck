#include "interpret_file.hpp"

void FBF::interpret_file(const std::string &path, bool in_line) {
	constexpr std::size_t SIZE = 30000;
	std::vector<uint8_t> arr(SIZE);
	std::vector<uint8_t>::iterator pointer = arr.begin();
	std::unordered_map<std::string, std::string> function_map;

	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open file!" << std::endl;
		exit(1);
	}

	std::string input((std::istreambuf_iterator<char>(inputFile)),
		(std::istreambuf_iterator<char>()));

	std::string location;

	location = FBF::find_parent(path);

	location = std::string(std::filesystem::current_path().u8string()) + (path[0] == '/' ? "" : "/") + location;

	std::ofstream log_file(location + "file_log.fbf.log");
	log_file << "";
	log_file.close();

	FBF::eval_string(input, pointer, arr, function_map, location, location + "/file_log.fbf.log", in_line);

	if (function_map["main"] == "") {
		std::cerr << "\nEmpty or no main definition!\n" << std::endl;
	}
	else {
		FBF::eval_string(function_map["main"], pointer, arr, function_map, location, location + "/file_log.fbf.log", in_line);
	}
	exit(0);
}