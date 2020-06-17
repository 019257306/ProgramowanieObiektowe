#ifndef Table_h
#define Table_h

#include <iostream>
#include <fstream>

#define FILE "file.txt"

using namespace std;

// Struct containing an array and data about it
class Array {
private:
	int **array,            // The array
		rows = 0,         // Amount of rows
        columns = 0;      // Amount of columns

public:
	/**
	 * @param[int] new_width - new value of width
	 * @param[int] new_height - new value of height
	 */
	void changeSize(int, int);          // Change size of the array

	/**
	 * @param[int] xPos - column index
	 * @param[int] yPos - row index
	 * @param[int] new_data - new data with variable type
	 */
	void changeData(int, int, int);     // Change a particlar cell
	void display(void);                 // Print all the array
	void write(void);                   // Save the array to the disk
	void read(void);                    // Load the array from the disk

	/**
	 * @param[int] column - column index
	 */
	void findColumnMin(int);

	/**
	 * @param[int] column - column index
	 */
	void findColumnMax(int);

	/**
	 * @param[int] column - column index
	 */
	void findColumnMedium(int);

	/**
	 * @param[int] column - column index
	 */
	void findColumnSum(int);

	/**
	 * @param[int] row - row index
	 */
	void findRowMin(int);

	/**
	 * @param[int] row - row index
	 */
	void findRowMax(int);

	/**
	 * @param[int] row - row index
	 */
	void findRowMedium(int);

	/**
	 * @param[int] row - row index
	 */
	void findRowSum(int);
};

#endif
