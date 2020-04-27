#include "table.h"

void display(Table& table) {
	for(int i = 0; i < table.columns; ++i) {
		for(int j = 0; j < table.rows; ++j) cout << table.table[i][j] << " ";

		cout << endl;
	}
}

void changeData(Table& table, int xPos , int yPos, int new_data) {
		if (yPos > table.rows || xPos > table.columns)	cout << "Niepoprawna wartosc" << endl;

		else table.table[xPos][yPos] = new_data;
}

void changeSize(Table& table, int new_width, int new_height) {
	int** column_ptr = new int*[new_height];
	int* row_ptr;

	for(int column = 0; column < table.columns; ++column) {
		cout << "Moving" << endl;
		for (int row = 0; row < table.rows; ++row) {
			row_ptr = new int[new_width];
			row_ptr[row] = table.table[column][row];
		}

		column_ptr[column] = row_ptr;
	}

	for (int column = table.columns; column < new_height; ++column) {
		row_ptr = new int[new_width];

		column_ptr[column] = row_ptr;
	}

	table.columns = new_height;
	table.rows = new_width;
	table.table = column_ptr;
}

void write(Table& table) {
	fstream outfile;
	outfile.open(FILE, ios::out);

	for(int i = 0; i < table.columns; ++i) {
		for(int j = 0; j < table.rows; ++j) outfile << table.table[i][j] << " ";

		outfile << endl;
	}

	outfile.close();
}

void read(Table& table) {
	fstream infile;
	infile.open(FILE, ios::in);

	// Your code

	infile.close();
}
