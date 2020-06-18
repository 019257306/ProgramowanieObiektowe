#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <sstream>
#include "array.h"

using namespace std;

template <class FirstType, class SecondType, class ThirdType>
class Menu final {
private:
  Array<FirstType>* firstTypeArray;		// First colomn
  Array<SecondType>* secondTypeArray;	// Second columns
  Array<ThirdType>* thirdTypeArray;		// Third column

  void sizeChangeMenu(void);      // Change size submenu
  void dataChangeMenu(void);      // Change data submenu
  void display(void);
  void write(void);                   // Save the array to the disk
  void read(void);                    // Load the array from the disk

public:
  Menu();

  int ask(void);					// Ask user
  void print(void);					// Print menu entries
  int execute(int);					// Start executing the main sequence
};


template <class FirstType, class SecondType, class ThirdType>
Menu<FirstType, SecondType, ThirdType>::Menu() {
	firstTypeArray = new Array<FirstType>();
	secondTypeArray = new Array<SecondType>();
	thirdTypeArray = new Array<ThirdType>();
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::display(void) {
	std::cout << std::endl;

	for (int row = 0; row < firstTypeArray->getRows(); ++row) {
		std::cout << firstTypeArray->get(0, row).getData() << " ";
		std::cout << secondTypeArray->get(0, row).getData() << " ";
		std::cout << thirdTypeArray->get(0, row).getData();
		std::cout << std::endl;
	}
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::read(void) {
	FirstType firstTypeData;
	SecondType secondTypeData;
	ThirdType thirdTypeData;
	std::string line;
	int current_row = 0;

	// Open new file
	fstream infile;
	infile.open(FILE, ios::in);

	// Read file line-by-line while not EOF
	while(std::getline(infile, line)) {
		// Parse a line
		std::stringstream linestream(line);
		linestream >> firstTypeData >> secondTypeData >> thirdTypeData;

		//std::cout << firstTypeData << " " << secondTypeData << " " << thirdTypeData << std::endl;

		// Resize all the arrays
		firstTypeArray->changeSize(current_row + 1);
		secondTypeArray->changeSize(current_row + 1);
		thirdTypeArray->changeSize(current_row + 1);

		// Write new data
		firstTypeArray->changeData(0, current_row, firstTypeData);
		secondTypeArray->changeData(0, current_row, secondTypeData);
		thirdTypeArray->changeData(0, current_row, thirdTypeData);

		//
		++current_row;
	}

	// Close the file
	infile.close();
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::write(void) {
	// Open new file
	fstream outfile;
	outfile.open(FILE, ios::out);

	for (int row = 0; row < firstTypeArray->getRows(); ++row) {
		outfile << firstTypeArray->get(0, row).getData() << " ";
		outfile << secondTypeArray->get(0, row).getData() << " ";
		outfile << thirdTypeArray->get(0, row).getData();
		outfile << std::endl;
	}

	// Close the file
	outfile.close();
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::dataChangeMenu(void) {
	int xPos,				// Position in a row
	  	yPos;				// Position in a collumn

	// New data
	FirstType firstTypeData;
	SecondType secondTypeData;
	ThirdType thirdTypeData;

	// Ask user about new values
	cout << "Row number : ";
	cin >> yPos;
	cout << "Column number : ";
	cin >> xPos;
	cout << "New data in the cell : ";

	switch (xPos) {
		case 0:
			cin >> firstTypeData;
			firstTypeArray->changeData(0, yPos, firstTypeData);
			break;

		case 1:
			cin >> secondTypeData;
			secondTypeArray->changeData(0, yPos, secondTypeData);
			break;

		case 2:
			cin >> thirdTypeData;
			thirdTypeArray->changeData(0, yPos, thirdTypeData);
			break;

		default :
			std::cout << "Re-enter a column number:" << std::endl;
	}
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::sizeChangeMenu(void) {
	int new_width;			// New width

	// Ask user about new values
	cout << "New length: ";
	cin >> new_width;

	// Update size
	firstTypeArray->changeSize(new_width);
	secondTypeArray->changeSize(new_width);
	thirdTypeArray->changeSize(new_width);
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::print(void) {
	cout << endl;
	cout << "========= MENU =========" << endl;
	cout << "0.Exit the program" << endl;
	cout << "1.Change size (initial)" << endl;
	cout << "2.Change data of a specific cell" << endl;
	cout << "3.Display the array" << endl;
	cout << "4.Write data into a file" << endl;
	cout << "5.Read data from the file" << endl;
	cout << endl;
}


/**
 * @return - menu index choice
 */
template <class FirstType, class SecondType, class ThirdType>
int Menu<FirstType, SecondType, ThirdType>::ask(void) {
	int choice;								// Temporary variable to store user's choice

	// Commad prompt
	cout << "Enter your choice : ";
	cin >> choice;

	return choice;
}


/**
 * @param[int] choice - menu index
 * @return - 0 if exit comment and 1 in other cases
 */
template <class FirstType, class SecondType, class ThirdType>
int Menu<FirstType, SecondType, ThirdType>::execute(int choice) {
	// Execute corresponding function
	switch(choice) {
		case 0:
			return 0;

		case 1:
			sizeChangeMenu();
			break;

		case 2:
			dataChangeMenu();
			break;

		case 3:
			display();
			break;

		case 4:
			write();
			break;

		case 5:
			read();
			break;
	}

	return 1;
}

#endif
