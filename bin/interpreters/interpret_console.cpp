#include "interpret_console.hpp"

void FBF::interpret_console(bool in_line) {
	std::string input;
	constexpr std::size_t SIZE = 30000;
	std::vector<uint8_t> arr(SIZE);
	std::vector<uint8_t>::iterator pointer = arr.begin();
	std::unordered_map<std::string, std::string> function_map;
	std::string log_file_location = std::filesystem::current_path().u8string() + "/console_log.fbf.log";

	std::ofstream log_file(log_file_location);
	log_file << "";
	log_file.close();

	while (true) {
		std::cout << ">>>";
		while (input.empty()) {
			std::getline(std::cin, input);
		}
		FBF::eval_string(input, pointer, arr, function_map, std::filesystem::current_path().u8string() + "/CONSOLE", log_file_location, in_line);
		input = "";
	}
}