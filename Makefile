flags= -std=c++17 -Wall
INSTALL_DIR= /usr/local/bin/FBF
COMPILED_DIR = bin

ifeq ($(OS),Windows_NT)
    	DELETE_CMD := del
	else
    	DELETE_CMD := rm
	endif

all: $(COMPILED_DIR)/FBF
	@echo "\nInstalled brainfuck\n" 

install-linux: $(COMPILED_DIR)/FBF
	sudo install -m 755 FBF $(INSTALL_DIR)
	@echo "\nInstalled brainfuck\n"

remove-linux:
	make clean
	-$(DELETE_CMD) -$(COMPILED_DIR)\FBF

$(COMPILED_DIR)/FBF: $(COMPILED_DIR)/string_utils.o $(COMPILED_DIR)/eval_string.o $(COMPILED_DIR)/interpret_file.o $(COMPILED_DIR)/interpret_console.o $(COMPILED_DIR)/main.o
	g++ $(flags) $(COMPILED_DIR)/string_utils.o $(COMPILED_DIR)/eval_string.o $(COMPILED_DIR)/interpret_console.o $(COMPILED_DIR)/interpret_file.o $(COMPILED_DIR)/main.o -o $(COMPILED_DIR)/FBF

$(COMPILED_DIR)/string_utils.o: functional-brainfuck/string_utils.cpp
	g++ $(flags) -c functional-brainfuck/string_utils.cpp -o $(COMPILED_DIR)/string_utils.o

$(COMPILED_DIR)/eval_string.o: functional-brainfuck/eval/eval_string.cpp
	g++ $(flags) -c functional-brainfuck/eval/eval_string.cpp -o $(COMPILED_DIR)/eval_string.o

$(COMPILED_DIR)/interpret_file.o: functional-brainfuck/interpreters/interpret_file.cpp
	g++ $(flags) -c functional-brainfuck/interpreters/interpret_file.cpp -o $(COMPILED_DIR)/interpret_file.o

$(COMPILED_DIR)/interpret_console.o: functional-brainfuck/interpreters/interpret_console.cpp
	g++ $(flags) -c functional-brainfuck/interpreters/interpret_console.cpp -o $(COMPILED_DIR)/interpret_console.o

$(COMPILED_DIR)/main.o: functional-brainfuck/main.cpp
	g++ $(flags) -c functional-brainfuck/main.cpp -o $(COMPILED_DIR)/main.o

ifeq ($(OS),Windows_NT)
    	CLEAN_CMD := del /s *.o
	else
    	CLEAN_CMD := find . -type f -name "*.o" -delete
	endif

.PHONY: clean
clean:
	-$(CLEAN_CMD)
	-$(DELETE_CMD) $(COMPILED_DIR)\FBF.exe
	-$(DELETE_CMD) $(COMPILED_DIR)\FBF