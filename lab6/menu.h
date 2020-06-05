#ifndef Menu_h
#define Menu_h

#include <iostream>
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
			firstTypeArray->changeData(xPos, yPos, firstTypeData);
			break;

		case 1:
			cin >> secondTypeData;
			secondTypeArray->changeData(xPos, yPos, secondTypeData);
			break;

		case 2:
			cin >> thirdTypeData;
			thirdTypeArray->changeData(xPos, yPos, thirdTypeData);
			break;

		default :
			std::cout << "Re-enter a column number" << std::endl;
	}
}

template <class FirstType, class SecondType, class ThirdType>
void Menu<FirstType, SecondType, ThirdType>::sizeChangeMenu(void) {
	int new_width;			// New width

	// Ask user about new values
	cout << "New length : " << endl;
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

template <class FirstType, class SecondType, class ThirdType>
int Menu<FirstType, SecondType, ThirdType>::ask(void) {
	int choice;								// Temporary variable to store user's choice

	// Commad prompt
	cout << "Enter your choice : ";
	cin >> choice;

	return choice;
}

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
			firstTypeArray->display();
			secondTypeArray->display();
			thirdTypeArray->display();
			break;

		case 4:
			firstTypeArray->write();
			secondTypeArray->write();
			thirdTypeArray->write();
			break;

		case 5:
			firstTypeArray->read();
			secondTypeArray->read();
			thirdTypeArray->read();
			break;
	}

	return 1;
}

#endif
