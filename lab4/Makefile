CXX = g++
CXXFLAGS = -Os -c

all : build/main.out

clean :
	rm -rf build
	mkdir build
	rm -f file.txt

build/array.o : array.cpp array.h
	$(CXX) $(CXXFLAGS) array.cpp -o $@

build/menu.o : menu.cpp menu.h
	$(CXX) $(CXXFLAGS) menu.cpp -o $@

build/main.o :
	$(CXX) $(CXXFLAGS) main.cpp  -o $@

build/main.out : build/main.o build/menu.o build/array.o
	$(CXX) $^ -o $@
