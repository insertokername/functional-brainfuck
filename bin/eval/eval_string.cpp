#include "eval_string.hpp"

void FBF::eval_string(const std::string &input
	, std::vector<uint8_t>::iterator &pointer
	, std::vector<uint8_t> &arr
	, std::unordered_map<std::string, std::string> &function_map
	, std::string location
	, bool in_line) {

	std::stack<std::size_t> loop_stack;
	int16_t skipping_loop = 0;

	for (std::size_t i = 0;i < input.size();i++) {
		if (!skipping_loop) {
			FBF::eval_char(input[i], pointer, arr);
		}
		switch (input[i]) {
			case '#': {
				std::string name, body;
				std::size_t start = i + 1, end;

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

				i = end;
				if (name.empty() || body.empty()) {
					std::cerr << "Unclosed include statement!" << std::endl;
					exit(1);
				}

				std::ifstream input_file(location + "/" + name);
				if (!input_file.is_open()) {
					std::cerr << "Failed to open " << name << "!" << std::endl;
					exit(1);
				}

				std::string input_file_text((std::istreambuf_iterator<char>(input_file)),
					(std::istreambuf_iterator<char>()));
				FBF::eval_string(input_file_text, pointer, arr, function_map, location + "/" + FBF::find_parent(name), std::stoi(body));
				break;
			}
			case '|': {
				std::string name;
				std::size_t start = i + 1, end = input.find("|", start);

				if (end == std::string::npos) {
					std::cerr << "Unclosed function call!" << std::endl;
					exit(1);
				}
				name = input.substr(start, end - start);

				FBF::eval_string(function_map[name], pointer, arr, function_map, location, in_line);
				i = end;
				break;
			}
			case '=': {
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
					std::cerr << "Unclosed function definition!" << std::endl;
					exit(1);
				}
				function_map[name] = body;
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
				if (in_line) {
					if (i + 1 < input.size()) {
						i++;
						(*pointer) = input[i];
					}
					else {
						std::cin >> (*pointer);
					}
				}
				else {
					std::cin >> (*pointer);
				}
				break;
			}
		}
	}
	if (!loop_stack.empty()) {
		std::cerr << "Unclosed paranthases (paranthases stack not empty)!\n" << std::endl;
		exit(1);
	}
}