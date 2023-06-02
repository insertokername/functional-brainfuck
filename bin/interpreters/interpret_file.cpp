#include "interpret_file.hpp"

void FBF::interpret_file(const std::string &path, bool in_line) {
	constexpr std::size_t SIZE = 30000;
	std::vector<uint8_t> arr(SIZE);
	std::vector<uint8_t>::iterator pointer = arr.begin();
	std::unordered_map<std::string, std::string> function_map;

	std::ifstream inputFile(path);
	if (!inputFile.is_open()) {
		std::cerr << "Failed to open file: " << path << std::endl;
		exit(1);
	}

	std::string input((std::istreambuf_iterator<char>(inputFile)),
		(std::istreambuf_iterator<char>()));

	std::string location;

	//	location = FBF::find_parent(path);

	if (std::filesystem::path(path).is_absolute()) {
		location = path;
	}
	else {
		location = std::string(std::filesystem::current_path().u8string()) + "/" + path;
	}


	std::string log_file_path = FBF::find_parent(location) + "/file_log.fbf.log";
	std::ofstream log_file(log_file_path);
	log_file << "";
	log_file.close();

	FBF::eval_string(input, pointer, arr, function_map, location, log_file_path, in_line);

	if (function_map["main"] == "") {
		std::cerr << "Error in file: " << location << std::endl;
		std::cerr << "\nEmpty or no main definition!\n" << std::endl;
		exit(1);
	}

	FBF::eval_string(function_map["main"], pointer, arr, function_map, location, log_file_path, in_line);

	std::ofstream arr_log_file(FBF::find_parent(location) + "/arr_file_log.fbf.log");
	for (int i = 0;i < SIZE;i++) {
		if (arr[i]) {
			arr_log_file << (int)(arr[i]) << ' ';
		}
	}

	arr_log_file << "\n\n";

	for (int i = 0;i < SIZE;i++) {
		if (arr[i]) {
			arr_log_file << i << ' ';
		}
	}
	arr_log_file.close();
	exit(0);
}