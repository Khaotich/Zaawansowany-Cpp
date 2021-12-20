output: main.o 
	g++-11 -std=c++20 -pthread main.o -o main.out

main.o: main.cpp
	g++-11 -std=c++20 -pthread -c main.cpp -o main.o

clean:
	rm *.o output