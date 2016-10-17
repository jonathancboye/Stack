stack: main.o SStack.o
	g++ main.o SStack.o -o stack

main.o: main.cpp SStack.h all.last.txt
	g++ -c main.cpp

SStack.o: SStack.h SStack.cpp
	g++ -Wall -c SStack.cpp
clean:
	rm -f *~ *# *.o
