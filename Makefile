CXX = g++
CC = gcc
CFLAGS  = -Wall
CPPFLAGS= -Wall
LINKS = -lncurses
CPP_SRC=$(wildcard *.cpp)
CPP_OBJ=$(CPP_SRC:.cpp=.o)
OBJS=\
$(CPP_OBJ)\
$(C_OBJ)

.o.cpp:
	$(CXX) $(CPPFLAGS) $< -c -o $@
main: $(OBJS)
	$(CC) $< $(LINKS) -o $@
	$(RM) $(OBJS)

clean:
	$(RM) main $(OBJS)

run: main
	./main