#include "interpreters/interpret_file.hpp"
#include "interpreters/interpret_console.hpp"
#include <string>
#include <algorithm>
#include <iostream>

int main(int argc, char* argv[]) {

	bool force_in_line = 0, in_line = 0;
	for (int i = 1;i < argc;i++) {
		std::string arg = argv[i];
		std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);

		if (arg.length() > 1 && arg[0] == '-') {
			if (arg.substr(1, arg.size()) == "H") {
				std::cout << "-h help\n-e enable readig inline \n-d disable reading inline \n-f read from file mode \n-(Ctrl+D to stop a script and still get an output) \n";
				return 0;
			}
			else if ((arg.substr(1, arg.size()) == "E") && !force_in_line) {
				force_in_line = 1;
				in_line = 1;
			}
			else if ((arg.substr(1, arg.size()) == "D") && !force_in_line) {
				force_in_line = 1;
				in_line = 0;
			}
			else if (arg.substr(1, arg.size()) == "F") {
				if (i + 1 >= argc) {
					std::cerr << "No file path specified!" << std::endl;
					return 1;
				}
				if (!force_in_line) {
					in_line = 0;
				}
				BF::interpret_file(argv[i + 1], in_line);
				return 0;
			}
			else {
				std::cerr << "No flag \"" << arg.substr(1, arg.size()) << "\" exists" << std::endl;
			}
		}
	}
	if (!force_in_line) {
		in_line = 1;
	}
	BF::interpret_console(in_line);
	return 0;

}