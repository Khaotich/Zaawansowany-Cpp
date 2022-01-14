output: main.o list.o
	g++-11 -std=c++20 -pthread main.o list.o -o main.out

main.o: main.cpp
	g++-11 -std=c++20 -pthread -c main.cpp

list.o: list.cpp list.h
	g++-11 -std=c++20 -pthread -c list.cpp

clean:
	rm *.o output