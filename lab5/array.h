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
	void changeSize(int, int);          // Change size of the array
	void changeData(int, int, Type);     // Change a particlar cell
	void display(void);                 // Print all the array
	void write(void);                   // Save the array to the disk
	void read(void);                    // Load the array from the disk
};


template <class Type>
void Array<Type>::display(void) {
	// Print every cell
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < columns; ++j)
			cout << array[j][i] << " ";

		cout << endl;
	}
}

/**
 * @param[int] xPos - column index
 * @param[int] yPos - row index
 * @param[Type] new_data - new data with variable type
 */
template <class Type>
void Array<Type>::changeData(int xPos , int yPos, Type new_data) {
		// Check if position is incorrect
		if (yPos > rows || xPos > columns || xPos < 0 || yPos < 0)	cout << "Data is not correct" << endl;

		else array[xPos][yPos].setData(new_data);
}

/**
 * @param[int] new_width - new value of width
 * @param[int] new_height - new value of height
 */
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

template <class Type>
void Array<Type>::write(void) {
	// Open new file
	fstream outfile;
	outfile.open(FILE, ios::out);

	// Print every cell
	for(int i = 0; i < columns; ++i) {
		for(int j = 0; j < rows; ++j) outfile << array[i][j] << " ";

		outfile << endl;
	}

	// Close the file
	outfile.close();
}

template <class Type>
void Array<Type>::read(void) {
	// Open new file
	fstream infile;
	infile.open(FILE, ios::in);

	// Your code

	infile.close();
}

#endif
