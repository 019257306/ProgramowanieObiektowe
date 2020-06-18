#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>

#define FILE "file.txt"

using namespace std;

/**
 * @param[int**&] table - 2D array
 * @param[int] rows - amount of rows in the array
 * @param[int] columns - amount of columns in the array
 * @param[int] new_width - new value of width
 * @param[int] new_height - new value of height
 */
void changeSize(int**&, int&, int&, int, int);

/**
 * @param[int**] table - 2D array
 * @param[int] rows - amount of rows in the array
 * @param[int] columns - amount of columns in the array
 * @param[int] xPos - column index
 * @param[int] yPos - row index
 * @param[int] new_data - new data with variable type
 */
void changeData(int**, int, int, int, int, int);

/**
 * @param[int**] table - 2D array
 * @param[int] rows - amount of rows in the array
 * @param[int] columns - amount of columns in the array
 */
void display(int**, int, int);

/**
 * @param[int**] table - 2D array
 * @param[int] rows - amount of rows in the array
 * @param[int] columns - amount of columns in the array
 */
void write(int**, int, int);

/**
 * @param[int**] table - 2D array
 * @param[int] rows - amount of rows in the array
 * @param[int] columns - amount of columns in the array
 */
void read(int**, int, int);

#endif
