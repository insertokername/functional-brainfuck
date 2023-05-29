#include "interpret_console.hpp"

void FBF::interpret_console(bool in_line) {
	std::string input;
	constexpr std::size_t SIZE = 30000;
	std::vector<uint8_t> arr(SIZE);
	std::vector<uint8_t>::iterator pointer = arr.begin();
	std::unordered_map<std::string, std::string> function_map;
	while (true) {
		std::cout << ">>>";
		std::getline(std::cin, input);
		FBF::eval_string(input, pointer, arr, function_map, std::filesystem::current_path().u8string(), in_line);
	}
}