output: main.o a.o
	g++-11 -std=c++20 main.o a.o -o main.out

main.o: main.cpp
	g++-11 -std=c++20 -c main.cpp

a.o: a.cpp a.h
	g++-11 -std=c++20 -c a.cpp

clean:
	rm *.o output