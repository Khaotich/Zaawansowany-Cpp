output: main.o 
	g++-11 -std=c++20 -fopenmp main.o -o main.out

main.o: main.cpp
	g++-11 -std=c++20 -fopenmp -c main.cpp -o main.o

clean:
	rm *.o output