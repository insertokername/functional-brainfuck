#include "interpret_console.hpp"
#include <fstream>

void FBF::interpret_console(int flags) {
	std::string input;
	constexpr std::size_t SIZE = 30000;
	std::vector<uint8_t> arr(SIZE);
	std::vector<uint8_t>::iterator pointer = arr.begin();
	std::unordered_map<std::string, std::string> function_map;
	std::string log_file_location = FBF::make_valid_path(std::filesystem::current_path().u8string()) + "/console_log.fbf.log";

	std::fstream(log_file_location, std::ios::out | std::ios::trunc);
	std::fstream(FBF::make_valid_path(std::filesystem::current_path().u8string()) + "/arr_console_log.fbf.log", std::ios::out | std::ios::trunc);

	while (true) {
		std::cout << ">>>";
		while (input.empty()) {
			std::getline(std::cin, input);
		}
		FBF::eval_string(input, pointer, arr, function_map, FBF::make_valid_path(std::filesystem::current_path().u8string()) + "/CONSOLE", log_file_location, flags);
		input = "";

		std::ofstream arr_log_file(FBF::make_valid_path(std::filesystem::current_path().u8string()) + "/arr_console_log.fbf.log");
		arr_log_file << "value: ";
		for (std::size_t i = 0;i < SIZE;i++) {
			if (arr[i]) {
				arr_log_file << (int)(arr[i]) << ' ';
			}
		}

		arr_log_file << "\n\n";

		arr_log_file << "index: ";
		for (std::size_t i = 0;i < SIZE;i++) {
			if (arr[i]) {
				arr_log_file << i << ' ';
			}
		}
		arr_log_file.close();
	}
}