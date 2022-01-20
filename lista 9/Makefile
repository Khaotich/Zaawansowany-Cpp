all: main.out

main.out: main.o singleton_static.a singleton_dynamic.so
	g++ -lm -o main.out main.o -L. -lsingleton_static -L. -lsingleton_dynamic

main.o: main.cpp
	g++ -std=c++17 -c -g -Wall -pedantic -Werror -o main.o main.cpp

#static library
singleton.o: singleton.cpp singleton.h
	g++ -c -Wall -pedantic -Werror singleton.cpp

calls1.o: calls1.cpp calls1.h
	g++  -std=c++17 -c -Wall -pedantic -Werror calls1.cpp

singleton_static.a: singleton.o calls1.o
	ar rcs libsingleton_static.a singleton.o calls1.o

libs: singleton_static.a

#dynamic library
singleton.o: singleton.cpp singleton.h
	g++ -fPIC -std=c++17 -c -Wall -pedantic -Werror singleton.cpp

singleton_dynamic.o: singleton_dynamic.cpp singleton_dynamic.h
	g++ -fPIC -std=c++17 -c -Wall -pedantic -Werror singleton_dynamic.cpp

singleton_dynamic.so: singleton.o singleton_dynamic.o
	g++ -shared -o libsingleton_dynamic.so singleton.o singleton_dynamic.o

#aby program main działał trzeba dołączyć bibliotekę (kropka to obecny folder)
#LD_LIBRARY_PATH=. 
#export LD_LIBRARY_PATH=.

clean:
	rm -f main *.o *.a *.gch *.out