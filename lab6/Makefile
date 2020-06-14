CXX = g++
CXXFLAGS = -std=c++11 -O1 -c
RM = rm
RMFLAGS = -rf
MKDIR = mkdir

.PHONY: all

all : build/main.out

clean :
	$(RM) $(RMFLAGS) build
	$(MKDIR) build
	$(RM) $(RMFLAGS) file.txt

build/main.o : main.cpp
	$(CXX) $(CXXFLAGS) $<  -o $@

build/main.out : build/main.o
	$(CXX) $^ -o $@
