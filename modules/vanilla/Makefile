PACKNAME = vanilla

CXX = g++
FILES = $(wildcard *.cpp)

main: $(OBJS)
	for FILE in $(FILES); do g++ -c -fPIC $$FILE -o $${FILE%.*}.so; done
clean:
	for FILE in $(FILES); do rm -f $${FILE%.*}.so; done

cleanall: clean
	rm -f $(PACKNAME).zip

pack: main
	zip $(PACKNAME) manifest.mf *.so
	make clean