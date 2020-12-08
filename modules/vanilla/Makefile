PACKNAME = vanilla

CXX = g++
FILES = $(wildcard *.cpp)
OBJS=$(FILES:.cpp=.so)
%.so: %.cpp
	g++ -shared $< -o $@
main: $(OBJS)

clean:
	rm -f $(OBJS)
cleanall: clean
	rm -f $(PACKNAME).zip

pack: main
	zip $(PACKNAME) manifest.mf *.so
	make clean
