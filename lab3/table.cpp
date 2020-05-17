#include "table.h"

void display(Table& table) {
	// Print every cell
	for(int i = 0; i < table.columns; ++i) {
		for(int j = 0; j < table.rows; ++j) cout << table.table[i][j] << " ";

		cout << endl;
	}
}

void changeData(Table& table, int xPos , int yPos, int new_data) {
		// Check if position is incorrect
		if (yPos > table.rows || xPos > table.columns)	cout << "Niepoprawna wartosc" << endl;

		else table.table[xPos][yPos] = new_data;
}

void changeSize(Table& table, int new_width, int new_height) {
	int** column_ptr = new int*[new_height];		// New array
	int* row_ptr;																// Temporary pointer for rows

	// Move old data to the new location
	for(int column = 0; column < table.columns; ++column) {
		for (int row = 0; row < table.rows; ++row) {
			row_ptr = new int[new_width];
			row_ptr[row] = table.table[column][row];
		}

		column_ptr[column] = row_ptr;
	}

	// Delete old array
	delete[] table;

	// Add new rows to the new array
	for (int column = table.columns; column < new_height; ++column) {
		row_ptr = new int[new_width];

		column_ptr[column] = row_ptr;
	}

	// Update data
	table.columns = new_height;
	table.rows = new_width;
	table.table = column_ptr;
}

void write(Table& table) {
	// Open new file
	fstream outfile;
	outfile.open(FILE, ios::out);

	// Print every cell
	for(int i = 0; i < table.columns; ++i) {
		for(int j = 0; j < table.rows; ++j) outfile << table.table[i][j] << " ";

		outfile << endl;
	}

	// Close the file
	outfile.close();
}

void read(Table& table) {
	// Open new file
	fstream infile;
	infile.open(FILE, ios::in);

	// Your code

	infile.close();
}
