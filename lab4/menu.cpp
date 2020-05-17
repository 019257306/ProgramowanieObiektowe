#include "menu.h"

Menu::Menu(Array* new_array) {
	array = new_array;
}

void Menu::dataChangeMenu(void) {
	  int xPos,					// Position in a row
	  		yPos,				// Position in a collumn
	  		new_data;			// New data

	  cout << "Row number : " << endl;
	  cin >> yPos;
	  cout << "Column number : " << endl;
	  cin >> xPos;
	  cout << "New data in the cell" << endl;
	  cin >> new_data;

		// Ask user about new values
	  array->changeData(xPos, yPos, new_data);
}

void Menu::sizeChangeMenu(void) {
	int new_width,			// New width
		new_height;			// New height

	// Ask user about new values
	cout << "New length" << endl;
	cin >> new_width;
	cout << "New width" << endl;
	cin >> new_height;

	// Call a corresponding function
	array->changeSize(new_width, new_height);
}

void Menu::print(void) {
	cout << "========= MENU =========" << endl;
	cout << "1.Change size (initial)" << endl;
	cout << "2.Change data of a specific cell" << endl;
	cout << "3.Display the array" << endl;
	cout << "4.Write data into a file" << endl;
	cout << "5.Read data from the file" << endl;
	cout << endl;
}

char Menu::ask(void) {
	char choice;								// Temporary variable to store user's choice

	// Commad prompt
	cout << "Enter your choice : ";
	cin >> choice;

	return choice;
}

int Menu::execute(char choice) {
	// Execute corresponding function
	switch(choice) {
		case '1':
			sizeChangeMenu();
			break;

		case '2':
			dataChangeMenu();
			break;

		case '3':
			array->display();
			break;

		case '4':
			array->write();
			break;

		case '5':
			array->read();
			break;

		default:
			return 0;
	}

	return 1;
}
