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
		if (column < new_height) {
			for (int row = 0; row < table.rows; ++row) {
				if (row < new_width) {
					row_ptr = new int[new_width];
					row_ptr[row] = table.table[column][row];
				}
			}

			column_ptr[column] = row_ptr;
		}
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
	int rows,								// Rows amount in the array
	columns,									// Columns amount in the array
	pos = 0, 								// Delimiter position in the line read from the file
	data;										// Data to write into the array
	std::string line;						// Line read from the file
	std::stringstream linestream;		// Stream that converts the line to data

	// Open new file
	fstream infile;
	infile.open(FILE, ios::in);

	// Read size of a 2D array
	infile >> rows >> columns;

	// Resize the array
	table.changeSize(rows, columns);

	// Fill the array
	for (int row = 0; row != rows; ++row) {
		//
		std::getline(infile, line);

		for (int column = 0; column != columns; ++column) {
			// Find delimiter position
			pos = line.find(" ");

			// Convert string to the needed type
			linestream = std::stringstream(line.substr(0, pos));
			linestream >> data;

			// Write new data
			table.changeData(column, row, data);

			// Update the string
			line.erase(0, pos + 1);
		}
	}

	// Close the file
	infile.close();
}
