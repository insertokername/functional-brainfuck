#ifndef START_INTERPRETER_FBF_HPP
#define START_INTERPRETER_FBF_HPP

#include "../eval/eval_string.hpp"
#include "../flags.hpp"
#include "../string_utils.hpp"
#include <filesystem>

namespace FBF {
	void interpret_console(int flags);
}

#endif