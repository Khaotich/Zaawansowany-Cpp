output: main.o 
	g++-11 -std=c++20 main.o -o main.out

main.o: main.cpp Wektor.hpp
	g++-11 -std=c++20 -c main.cpp -o main.o

clean:
	rm *.o output