CXX = g++
CPPFLAGS= -Wall -std=c++17 -g
LINKS = -lncurses -lzip -ldl
CPP_SRC=$(wildcard *.cpp)
CPP_OBJ=$(CPP_SRC:.cpp=.o)
OBJS= $(CPP_OBJ) $(C_OBJ)
%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $< -c -o $@
75turns: $(OBJS)
	$(CXX) $^ $(LINKS) -o $@
	$(RM) $(OBJS)

clean:
	$(RM) main $(OBJS)

run: 75turns
	./75turns