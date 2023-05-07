
all: BF
	make clean
	@echo "\n\nInstalled brainfuck\n" 

uninstall:
	make clean
	sudo rm -f BF

#install for deb(not sure if it works on other distros i just made this for my pc) and automatically moves it in 
#the local bin folder for easy acces
install-deb: BF
	sudo install -m 755 BF /usr/local/bin/BF
	make clean
	@echo "\n\nInstalled brainfuck\n"

uninstall-deb:
	make clean
	sudo rm -f /usr/local/bin/BF

BF: BF.o main.o
	g++ -std=c++11 -Wall BF.o main.o -o BF

BF.o: bin/BF.cpp
	g++ -std=c++11 -Wall -c bin/BF.cpp -o BF.o

main.o: bin/main.cpp
	g++ -std=c++11 -Wall -c bin/main.cpp -o main.o

.PHONY: clean
clean:
	-rm -f *.o