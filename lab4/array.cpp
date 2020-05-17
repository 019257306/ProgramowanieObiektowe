#include "array.h"

void Array::display(void) {
	// Print every cell
	for(int i = 0; i < columns; ++i) {
		for(int j = 0; j < rows; ++j) cout << array[i][j] << " ";

		cout << endl;
	}
}

void Array::changeData(int xPos , int yPos, int new_data) {
		// Check if position is incorrect
		if (yPos > rows || xPos > columns || xPos < 0 || yPos < 0)	cout << "Data is not correct" << endl;

		else array[xPos][yPos] = new_data;
}

void Array::changeSize(int new_width, int new_height) {
	int** column_ptr = new int*[new_height];		// New array
	int* row_ptr;																// Temporary pointer for rows

	// Check if position is incorrect
	if (xPos < 0 || yPos < 0)	cout << "Data is not correct" << endl;

	else {
		// Move old data to the new location
		for(int column = 0; column < columns; ++column) {
			for (int row = 0; row < rows; ++row) {
				row_ptr = new int[new_width];
				row_ptr[row] = array[column][row];
			}

			column_ptr[column] = row_ptr;
		}

		// Delete old array
		delete[] array;

		// Add new rows to the new array
		for (int column = columns; column < new_height; ++column) {
			row_ptr = new int[new_width];

			column_ptr[column] = row_ptr;
		}

		// Update data
		columns = new_height;
		rows = new_width;
		array = column_ptr;
	}
}

void Array::write(void) {
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

void Array::read(void) {
	// Open new file
	fstream infile;
	infile.open(FILE, ios::in);

	// Your code

	infile.close();
}
