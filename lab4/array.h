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
	void changeSize(int, int);          // Change size of the array
	void changeData(int, int, int);     // Change a particlar cell
	void display(void);                 // Print all the array
	void write(void);                   // Save the array to the disk
	void read(void);                    // Load the array from the disk
	void findColumnMin(int);
	void findColumnMax(int);
	void findColumnMedium(int);
	void findColumnSum(int);
	void findRowMin(int);
	void findRowMax(int);
	void findRowMedium(int);
	void findRowSum(int);
};

#endif
