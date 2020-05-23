#include "array.h"

void Array::display(void) {
	// Print every cell
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < columns; ++j)
			cout << array[j][i] << " ";

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
	if (new_width < 0 || new_height < 0)
		cout << "Data is not correct" << endl;

	else {
		// Move old data to the new location
		for(int column = 0; column < columns; ++column) {
			for (int row = 0; row < rows; ++row) {
				row_ptr = new int[new_width];
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

void Array::findColumnMin(int column) {
	int min = array[column][0];

	// If a value is lower than current min then make it a new min value
	for (int index = 1; index != rows; ++index)
		if (min > array[column][index])
			min = array[column][index];

	cout << "Minimum value of the column is : " << min << endl;
}

void Array::findColumnMax(int column) {
	int max = array[column][0];

	// If a value is greater than current max then make it a new max value
	for (int index = 1; index != rows; ++index)
		if (max < array[column][index])
			max = array[column][index];

	cout << "Maximum value of the column is : " << max << endl;
}

void Array::findColumnMedium(int column) {
	int medium = array[column][0];

	// Add all the values
	for (int index = 1; index != rows; ++index)
			medium += array[column][index];

	// Divide to obtain a medium value
	medium = medium / rows;

	cout << "Medium value of the column is : " << medium << endl;
}

void Array::findColumnSum(int column) {
	int sum = array[column][0];

	// Add all the values
	for (int index = 1; index != rows; ++index)
			sum += array[column][index];

	cout << "Sum of the column is : " << sum << endl;
}

void Array::findRowMin(int row) {
	int min = array[0][row];

	// If a value is lower than current min then make it a new min value
	for (int index = 1; index != columns; ++index)
		if (min > array[index][row])
			min = array[index][row];

	cout << "Minimum value of the column is : " << min << endl;
}

void Array::findRowMax(int row) {
	int max = array[0][row];

	// If a value is greater than current max then make it a new max value
	for (int index = 1; index != columns; ++index)
		if (max < array[index][row])
			max = array[index][row];

	cout << "Maximum value of the column is : " << max << endl;
}

void Array::findRowMedium(int row) {
	int medium = array[0][row];

	// Add all the values
	for (int index = 1; index != columns; ++index)
		medium += array[index][row];

	// Divide to obtain a medium value
	medium = medium / columns;

	cout << "Medium value of the column is : " << medium << endl;
}

void Array::findRowSum(int row) {
	int sum = array[0][row];

	// Add all the values
	for (int index = 1; index != columns; ++index) {
		sum += array[index][row];
	}

	cout << "Sum of the row is : " << sum << endl;
}
