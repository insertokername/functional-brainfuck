#include "eval_string.hpp"

void FBF::eval_string(const std::string &input
	, std::vector<uint8_t>::iterator &pointer
	, std::vector<uint8_t> &arr
	, std::unordered_map<std::string, std::string> &function_map
	, const std::string &location
	, const std::string &log_path
	, bool in_line
) {
	std::stack<std::size_t> loop_stack;
	int16_t skipping_loop = 0;
	std::ofstream log_file(log_path, std::ios::app);


	for (std::size_t i = 0;i < input.size();i++) {
		if (!skipping_loop) {
			FBF::eval_char(input[i], pointer, arr);
		}
		switch (input[i]) {
			case '#': {
				if (!skipping_loop) {
					std::string name;
					std::size_t start = i + 1, end = input.find("#", start);

					if (end == std::string::npos) {
						std::cerr << "Error in file: " << location << std::endl;
						std::cerr << "Unclosed include statement!" << std::endl;
						exit(1);
					}
					name = input.substr(start, end - start);
					i = end;

					/*
					while ((end = input.find("#", start)) != std::string::npos) {
						if (name.empty()) {
							// First occurrence of #
							name = input.substr(start, end - start);
						}
						else {
							// Second occurrence of #
							body = input.substr(start, end - start);
							break;
						}
						start = end + 1;
					}
					*/

					if (name.empty()) {
						std::cerr << "Error in file: " << location << std::endl;
						std::cerr << "Empty include statement!" << std::endl;
						exit(1);
					}

					std::ifstream input_file(FBF::find_parent(location) + "/" + name);
					if (!input_file.is_open()) {
						std::cerr << "Error in file: " << location << std::endl;
						std::cerr << "Failed to open " << name << "!" << std::endl;
						exit(1);
					}

					std::string input_file_text((std::istreambuf_iterator<char>(input_file)),
						(std::istreambuf_iterator<char>()));
					FBF::eval_string(input_file_text, pointer, arr, function_map, FBF::find_parent(location) + "/" + name, log_path, 0);
				}
				break;
			}
			case '|': {
				if (!skipping_loop) {
					std::string name;
					std::size_t start = i + 1, end = input.find("|", start);

					if (end == std::string::npos) {
						std::cerr << "Error in file: " << location << std::endl;
						std::cerr << "Unclosed function call!" << std::endl;
						exit(1);
					}
					name = input.substr(start, end - start);

					if (function_map[name] == "") {
						std::cerr << "Error in file: " << location << std::endl;
						std::cerr << "Undefined function: \"" << name << "\"" << std::endl;
						exit(1);
					}

					FBF::eval_string(function_map[name], pointer, arr, function_map, location, log_path, in_line);
					i = end;
				}
				break;
			}
			case '=': {
				if (!skipping_loop) {
					std::string name, body;
					std::size_t start = i + 1, end;

					while ((end = input.find("=", start)) != std::string::npos) {
						if (name.empty()) {
							// First occurrence of =
							name = input.substr(start, end - start);
						}
						else {
							// Second occurrence of =
							body = input.substr(start, end - start);
							break;
						}
						start = end + 1;
					}
					if (name.empty() || body.empty()) {
						std::cerr << "Error in file: " << location << std::endl;
						std::cerr << "Unclosed function definition!" << std::endl;
						exit(1);
					}
					function_map[name] = body;
					i = end;
				}
				break;
			}
			case '/': {
				std::size_t end = input.find("/", i + 1);
				if (end == std::string::npos) {
					std::cerr << "Error in file: " << location << std::endl;
					std::cerr << "Unclosed comment!" << std::endl;
					exit(1);
				}
				i = end;
				break;
			}
			case '[': {
				loop_stack.push(i);
				if ((*pointer) == 0) {
					skipping_loop++;
				}
				break;
			}
			case ']': {
				if (skipping_loop) {
					loop_stack.pop();
					skipping_loop--;
				}
				else {
					if ((*pointer) == 0) {
						loop_stack.pop();
					}
					else {
						i = loop_stack.top();
					}
				}
				break;
			}
			case ',': {
				if (skipping_loop) {
					break;
				}

				if (in_line && i + 1 < input.size()) {
					i++;
					(*pointer) = input[i];
				}
				else {
					char in;
					std::cin.get(in);
					*pointer = in;
				}
				break;
			}
		}
		if (input[i] == '~' && !skipping_loop) {
			log_file << "---" << std::endl;
		}
		else {
			log_file << "pointer position: " << pointer - arr.begin() << " pointer value: " << (int)(*pointer) << " (" << (*pointer) << ")" << " skipping loop: " << skipping_loop << " symbol: " << input[i] << std::endl;
		}
	}
	if (!loop_stack.empty()) {
		std::cerr << "Error in file: " << location << std::endl;
		std::cerr << "Unclosed paranthases (paranthases stack not empty)!\n" << std::endl;
		exit(1);
	}
	log_file.close();
}