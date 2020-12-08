CXX = g++
CPPFLAGS= -Wall -std=c++17 -g
LINKS = -lncurses -lzip -ldl
CPP_SRC=$(wildcard *.cpp)
main: $(CPP_SRC)
	$(CXX) $(CPPFLAGS) $(CPP_SRC) -o main $(LINKS)

clean:
	$(RM) main $(OBJS)

run: main
	./main