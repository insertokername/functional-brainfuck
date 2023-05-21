all: BF
	@echo "\nInstalled brainfuck\n" 

uninstall:
	make clean
	sudo rm -f BF

#install for deb(not sure if it works on other distros i just made this for my pc) and automatically moves it in 
#the local bin folder for easy acces
install-linux: BF
	sudo install -m 755 BF /usr/local/bin/BF
	@echo "\nInstalled brainfuck\n"

uninstall-linux:
	make clean
	sudo rm -f /usr/local/bin/BF

BF: eval_char.o eval_string.o interpret_file.o interpret_console.o main.o
	g++ -std=c++11 -Wall eval_char.o eval_string.o interpret_console.o interpret_file.o main.o -o BF

eval_char.o: bin/eval/eval_char.cpp 
	g++ -std=c++11 -Wall -c bin/eval/eval_char.cpp -o eval_char.o

eval_string.o: bin/eval/eval_char.cpp
	g++ -std=c++11 -Wall -c bin/eval/eval_string.cpp -o eval_string.o

interpret_file.o: bin/interpreters/interpret_file.cpp
	g++ -std=c++11 -Wall -c bin/interpreters/interpret_file.cpp -o interpret_file.o

interpret_console.o: bin/interpreters/interpret_console.cpp
	g++ -std=c++11 -Wall -c bin/interpreters/interpret_console.cpp -o interpret_console.o

main.o: bin/main.cpp
	g++ -std=c++11 -Wall -c bin/main.cpp -o main.o

.PHONY: clean
clean:
	-rm -f *.o