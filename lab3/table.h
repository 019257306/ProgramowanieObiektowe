#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>

#define FILE "file.txt"

using namespace std;

void changeSize(int**&, int&, int&, int, int);
void changeData(int**, int, int, int, int, int);
void display(int**, int, int);
void write(int**, int, int);
void read(int**, int, int);

#endif
