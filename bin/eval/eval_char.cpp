
#include "eval_char.hpp"

void FBF::eval_char(const char input, std::vector<uint8_t>::iterator &pointer, std::vector<uint8_t> &arr) {
	switch (std::tolower(input)) {
		case '>':
			pointer++;
			if (pointer == arr.end()) {
				pointer = arr.begin();
			}
			break;
		case '<':
			if (pointer == arr.begin()) {
				pointer = arr.end() - 1;
			}
			break;
		case '+':
			(*pointer)++;
			break;
		case '-':
			(*pointer)--;
			break;
		case 'q':
			exit(0);
			break;
		case '.':
			std::cout << (*pointer);
			break;
	}
}