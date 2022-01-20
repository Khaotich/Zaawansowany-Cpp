CC=g++
CFLAGS= -std=c++17
SOURCES= main.cpp engine.cpp tank.cpp
DEPS= engine.h tank.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.out

all: $(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) -o $@ -pthread

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp 

clean: 
	$(RM) *.o *~ $(EXECUTABLE)
