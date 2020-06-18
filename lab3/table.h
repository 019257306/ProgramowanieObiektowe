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

/**
 * @param[Table] table - link to a struct
 * @param[int] new_width - new value of width
 * @param[int] new_height - new value of height
 */
void changeSize(Table&, int, int);          // Change size of the array

/**
 * @param[Table] table - link to a struct
 * @param[int] xPos - column index
 * @param[int] yPos - row index
 * @param[int] new_data - new data with variable type
 */
void changeData(Table&, int, int, int);     // Change a particlar cell

/**
 * @param[Table] table - link to a struct
 */
void display(Table&);                       // Print all the array

/**
 * @param[Table] table - link to a struct
 */
void write(Table&);                         // Save the array to the disk

/**
 * @param[Table] table - link to a struct
 */
void read(Table&);                          // Load the array from the disk

#endif
