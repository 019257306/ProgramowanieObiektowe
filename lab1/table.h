#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>

#define FILE "file.txt"

using namespace std;

extern int** table;
extern int rows, columns;

void changeSize(int, int);
void changeData(int, int, int);
void display(void);
void write(void);
void read(void);

#endif
