CXX = g++
FILES = $(wildcard *.cpp)
OBJS=$(FILES:.cpp=.o)
CPPFLAGS?=
LINKS?=
build: modapi.a
modapi.a: $(OBJS)
	ar rvs $@ $^
%.o: %.cpp
	$(CXX) -fPIC $(CPPFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)