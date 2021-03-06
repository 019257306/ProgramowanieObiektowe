#include "table.h"

void display(int** table, int rows, int columns) {
	for(int i = 0; i < columns; ++i) {
		for(int j = 0; j < rows; ++j) cout << table[i][j] << " ";

		cout << endl;
	}
}

void changeData(int** table, int rows, int columns, int xPos , int yPos, int new_data) {
		if (yPos > rows || xPos > columns)	cout << "Niepoprawna wartosc" << endl;

		else table[xPos][yPos] = new_data;
}

void changeSize(int** table, int rows, int columns, int new_width, int new_height) {
	int** column_ptr = new int*[new_height];
	int* row_ptr;

	for(int column = 0; column < columns; ++column) {
		if (column < new_height) {
			for (int row = 0; row < rows; ++row) {
				if (row < new_width) {
					row_ptr = new int[new_width];
					row_ptr[row] = table[column][row];
				}
			}

			column_ptr[column] = row_ptr;
		}
	}

	for (int column = columns; column < new_height; ++column) {
		row_ptr = new int[new_width];

		column_ptr[column] = row_ptr;
	}

	columns = new_height;
	rows = new_width;
	table = column_ptr;
}

void write(int** table, int rows, int columns) {
	fstream outfile;
	outfile.open(FILE, ios::out);

	for(int i = 0; i < columns; ++i) {
		for(int j = 0; j < rows; ++j) outfile << table[i][j] << " ";

		outfile << endl;
	}

	outfile.close();
}

void read(int** table, int rows, int columns) {
	fstream infile;
	infile.open(FILE, ios::in);

	
	infile.close();
}
