#include "interpret_file.hpp"

void BF::interpret_file(char path[], bool in_line) {
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

	BF::eval_string(input, pointer, arr, function_map, in_line);

	if (function_map["main"] == "") {
		std::cerr << "\nEmpty or no main definition!\n" << std::endl;
	}
	else {
		BF::eval_string(function_map["main"], pointer, arr, function_map, in_line);
	}

	std::cout << '\n';
	exit(0);
}