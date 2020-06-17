#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "array.h"

using namespace std;

template <class Type>
class Menu final {
private:
  Array<Type>* array;

  void sizeChangeMenu(void);      // Change size submenu
  void dataChangeMenu(void);      // Change data submenu

public:
  Menu();

  int ask(void);					// Ask user
  void print(void);					// Print menu entries
  int execute(int);					// Start executing the main sequence
};


template <class Type>
Menu<Type>::Menu() { array = new Array<Type>(); }

template <class Type>
void Menu<Type>::dataChangeMenu(void) {
	int xPos,				// Position in a row
	  	yPos;				// Position in a collumn

	Type new_data;			// New data

	cout << "Row number : ";
	cin >> yPos;
	cout << "Column number : ";
	cin >> xPos;
	cout << "New data in the cell : ";
	cin >> new_data;

	// Ask user about new values
	array->changeData(xPos, yPos, new_data);
}

template <class Type>
void Menu<Type>::sizeChangeMenu(void) {
	int new_width,			// New width
		new_height;			// New height

	// Ask user about new values
	cout << "New length : " << endl;
	cin >> new_width;
	cout << "New width : " << endl;
	cin >> new_height;

	// Call a corresponding function
	array->changeSize(new_width, new_height);
}

template <class Type>
void Menu<Type>::print(void) {
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

template <class Type>
int Menu<Type>::ask(void) {
	int choice;								// Temporary variable to store user's choice

	// Commad prompt
	cout << "Enter your choice : ";
	cin >> choice;

	return choice;
}

template <class Type>
int Menu<Type>::execute(int choice) {
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
			array->display();
			break;

		case 4:
			array->write();
			break;

		case 5:
			array->read();
			break;
	}

	return 1;
}

#endif
