#include "eval_string.hpp"

void BF::eval_string(const std::string& input
	, std::vector<uint8_t>::iterator& pointer
	, std::vector<uint8_t>& arr
	, std::unordered_map<std::string, std::string>& function_map
	, bool in_line) {

	std::stack<std::size_t> loop_stack;
	int16_t skipping_loop = 0;

	for (std::size_t i = 0;i < input.size();i++) {
		if (!skipping_loop) {
			BF::evalChar(input[i], pointer, arr);
		}
		switch (input[i]) { //TODO make a version of paranteses skipping with stl so u dont have to use skipping_loop state
			case '|': {
				std::string name;
				std::size_t start = i + 1, end;
				end = input.find("|", start);

				if (end == std::string::npos) {
					std::cerr << "Unclosed function call!" << std::endl;
					exit(1);
				}
				name = input.substr(start, end - start);
				//std::clog<<"starting positiop of subst "<<start<<' '<<end<<'\n';
				//std::clog<<"running function "<<name<<" "<<function_map[name]<<std::endl;
				BF::eval_string(function_map[name], pointer, arr, function_map, in_line);
				i = end;
				break;
			}
			case '=': {
				std::string name, body;
				std::size_t start = i + 1, end;
				while ((end = input.find("=", start)) != std::string::npos) {
					if (name.empty()) {
						// First occurrence of `
						name = input.substr(start, end - start);
					}
					else {
						// Second occurrence of `
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
				//std::clog<<"saved "<<name<<" as body "<<function_map[name]<<std::endl;
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
		std::cerr << "Unclosed paranthases (stack not empty)!\n" << std::endl;
		exit(1);
	}
}