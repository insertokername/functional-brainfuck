
BF: BF.o main.o
	g++ -std=c++11 BF.o main.o -o BF

BF.o: bin/BF.cpp
	g++ -std=c++11 bin/BF.cpp -c BF.o

main.o: bin/main.cpp
	g++ -std=c++11 bin/main.cpp -c main.o

.PHONY: clean
clean:
	-rm *.o $(objects)  