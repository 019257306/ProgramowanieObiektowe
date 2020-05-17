#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>

#define FILE "file.txt"

using namespace std;

// Struct containing an array and data about it
struct Table {
  int **table,            // The array
        rows = 0,         // Amount of rows
        columns = 0;      // Amount of columns
};

void changeSize(Table&, int, int);          // Change size of the array
void changeData(Table&, int, int, int);     // Change a particlar cell
void display(Table&);                       // Print all the array
void write(Table&);                         // Save the array to the disk
void read(Table&);                          // Load the array from the disk

#endif
