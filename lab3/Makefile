CXX = g++
CXXFLAGS = -Os -c

all : build/tablica.out build/main.out

clean :
	rm -rf build
	mkdir build
	rm file.txt

build/table.o : table.cpp table.h
	$(CXX) $(CXXFLAGS) table.cpp -o $@

build/menu.o : menu.cpp menu.h
	$(CXX) $(CXXFLAGS) menu.cpp -o $@

build/tablica_wysw.o :
	$(CXX) $(CXXFLAGS) tablica_wysw.cpp -o $@

build/main.o :
	$(CXX) $(CXXFLAGS) main.cpp  -o $@

build/main.out : build/main.o build/menu.o build/table.o
	$(CXX) $^ -o $@

build/tablica.out : build/tablica_wysw.o build/menu.o build/table.o
	$(CXX) $^ -o $@
