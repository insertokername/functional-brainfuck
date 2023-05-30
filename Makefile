flags= -std=c++17 -Wall
INSTALL_DIR= /usr/local/bin/FBF
all: FBF
	@echo "\nInstalled brainfuck\n" 

.PHONY: uninstall-local
uninstall-local:
	make clean
	-rm -f FBF.exe


install-linux: FBF
	sudo install -m 755 FBF $(INSTALL_DIR)
	@echo "\nInstalled brainfuck\n"

uninstall-linux:
	make clean
	-rm -f FBF
	sudo rm -f $(INSTALL_DIR)

FBF: utils.o eval_char.o eval_string.o interpret_file.o interpret_console.o main.o
	g++ $(flags) utils.o eval_char.o eval_string.o interpret_console.o interpret_file.o main.o -o FBF

utils.o: bin/utils.cpp
	g++ $(flags) -c bin/utils.cpp -o utils.o

eval_char.o: bin/eval/eval_char.cpp 
	g++ $(flags) -c bin/eval/eval_char.cpp -o eval_char.o

eval_string.o: bin/eval/eval_char.cpp
	g++ $(flags) -c bin/eval/eval_string.cpp -o eval_string.o

interpret_file.o: bin/interpreters/interpret_file.cpp
	g++ $(flags) -c bin/interpreters/interpret_file.cpp -o interpret_file.o

interpret_console.o: bin/interpreters/interpret_console.cpp
	g++ $(flags) -c bin/interpreters/interpret_console.cpp -o interpret_console.o

main.o: bin/main.cpp
	g++ $(flags) -c bin/main.cpp -o main.o

.PHONY: clean
clean:
	-rm -f *.o