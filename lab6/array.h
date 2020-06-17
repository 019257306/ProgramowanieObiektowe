#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>
#include "cell.h"

#define FILE "file.txt"

using namespace std;

// Struct containing an array and data about it
template <class Type>
class Array final {
private:
	Cell<Type> **array;            // The array
	int rows = 0,         // Amount of rows
        columns = 0;      // Amount of columns

public:
	Array();

	void changeSize(int, int = 1);      // Change size of the array
	void changeData(int, int, Type);    // Change a particlar cell
	Cell<Type> get(int, int);                 // Get data from the array
	int getRows(void);
	int getColumns(void);
};

template <class Type>
Array<Type>::Array() {
	//
	array = new Cell<Type>*();

	//
	array[0] = new Cell<Type>();
}

template <class Type>
Cell<Type> Array<Type>::get(int column, int row) { return array[column][row]; }

template <class Type>
int Array<Type>::getRows(void) { return rows; }

template <class Type>
int Array<Type>::getColumns(void) { return columns; }

template <class Type>
void Array<Type>::changeData(int xPos , int yPos, Type new_data) {
		// Check if position is incorrect
		if (yPos > rows || xPos > columns || xPos < 0 || yPos < 0)	cout << "Data is not correct" << endl;

		else array[xPos][yPos].setData(new_data);
}

template <class Type>
void Array<Type>::changeSize(int new_width, int new_height) {
	Cell<Type>** column_ptr = new Cell<Type>*[new_height];		// New array
	Cell<Type>* row_ptr;																// Temporary pointer for rows

	// Check if position is incorrect
	if (new_width < 0 || new_height < 0)
		cout << "Data is not correct" << endl;

	else {
		// Move old data to the new location
		for(int column = 0; column < columns; ++column) {
			for (int row = 0; row < rows; ++row) {
				row_ptr = new Cell<Type>[new_width];
				row_ptr[row] = array[column][row];
			}

			column_ptr[column] = row_ptr;

			// Delete old array
			delete[] array[column];
		}

		// Delete old array
		delete[] array;

		// Add new rows to the new array
		for (int column = columns; column < new_height; ++column) {
			row_ptr = new Cell<Type>[new_width];

			column_ptr[column] = row_ptr;
		}

		// Update data
		columns = new_height;
		rows = new_width;
		array = column_ptr;
	}
}

#endif
