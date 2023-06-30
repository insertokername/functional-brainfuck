#include "interpret_file.hpp"

void FBF::interpret_file(const std::string &path, int flags) {
	constexpr std::size_t SIZE = 30000;
	std::vector<uint8_t> arr(SIZE);

	if (flags & READ_ARR_FROM_FILE) {
		std::ifstream in_arr_file("FBF_array.txt");
		std::string in_arr_line;
		std::size_t line_number = 0;
		while (std::getline(in_arr_file, in_arr_line)) {
			line_number++;
			std::size_t end = in_arr_line.find(": ");
			if (end == std::string::npos) {
				std::cerr << "Didn't find colums on line " << line_number << std::endl;
				continue;
			}

			try {
				std::size_t
					cell_number = std::stoi(in_arr_line.substr(0, end)),
					cell_value = std::stoi(in_arr_line.substr(end + 1, in_arr_line.size()));
				arr[cell_number] = cell_value;
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << '\n';
			}
		}
	}

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
		location = std::string(FBF::make_valid_path(std::filesystem::current_path().u8string())) + "/" + path;
	}

	if (input.find("=main=") == std::string::npos) {
		std::cerr << "Error in file: " << location << std::endl;
		std::cerr << "\nNo main definition!\n" << std::endl;
		exit(1);
	}

	std::string log_file_path = FBF::find_parent(location) + "/file_log.fbf.log";
	std::ofstream log_file(log_file_path);
	log_file << "";
	log_file.close();

	FBF::eval_string(input, pointer, arr, function_map, location, log_file_path, flags);

	if (function_map["main"] == "") {
		std::cerr << "Error in file: " << location << std::endl;
		std::cerr << "\nEmpty main definition!\n" << std::endl;
		exit(1);
	}

	FBF::eval_string(function_map["main"], pointer, arr, function_map, location, log_file_path, flags);

	std::ofstream arr_log_file(FBF::find_parent(location) + "/arr_file_log.fbf.log", std::ios::trunc);
	for (std::size_t i = 0;i < SIZE;i++) {
		if (arr[i]) {
			arr_log_file << (int)(arr[i]) << ' ';
		}
	}

	arr_log_file << "\n\n";

	for (std::size_t i = 0;i < SIZE;i++) {
		if (arr[i]) {
			arr_log_file << i << ' ';
		}
	}
	arr_log_file.close();
	exit(0);
}