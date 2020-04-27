#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>

#define FILE "file.txt"

using namespace std;

struct Table {
  int **table,
        rows = 0,
        columns = 0;
};

void changeSize(Table&, int, int);
void changeData(Table&, int, int, int);
void display(Table&);
void write(Table&);
void read(Table&);

#endif
