all : build/main.out build/tablica.out

clean : 
	rm -rf build
	mkdir build 

build/tablica_wysw.o :
	g++ -c tablica_wysw.cpp -o $@

build/main.o :
	g++ main.cpp -c -o $@

build/main.out : build/main.o
	g++ $< -o $@

build/tablica.out : build/tablica_wysw.o 
	g++ $< -o $@

