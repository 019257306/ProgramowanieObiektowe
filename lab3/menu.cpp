#include "menu.h"

void dataChangeMenu(Table& table) {
	  int xPos;					// Position in a row
	  int yPos;					// Position in a collumn
	  int new_data;			// New data

	  cout << "Numer wiersza:" << endl;
	  cin >> yPos;
	  cout << "Numer columny:" << endl;
	  cin >> xPos;
	  cout << "new data" << endl;
	  cin >> new_data;

		// Ask user about new values
	  changeData(table, xPos, yPos, new_data);
}

void sizeChangeMenu(Table& table) {
	int new_width;			// New width
	int new_height;			// New height

	// Ask user about new values
	cout << "Dlugosc:" << endl;
	cin >> new_width;
	cout << "Szerokosc:" << endl;
	cin >> new_height;

	// Call a corresponding function
	changeSize(table, new_width, new_height);
}

void mainMenu(void) {
	cout << "Menu:" << endl;
	cout << "1.Rozmiar" << endl;
	cout << "2.Data" << endl;
	cout << "3.Display" << endl;
	cout << "4.Write" << endl;
	cout << "5.Read" << endl;
}

bool run(void) {
	static Table table;			// Static Table struct
	char val;								// Temporary variable to store user's choice

	mainMenu();

	// Commad prompt
	cout << "Enter your choice : ";
	cin >> val;

	// Execute corresponding function
	switch(val) {
		case '1':
			sizeChangeMenu(table);
			break;

		case '2':
			dataChangeMenu(table);
			break;

		case '3':
			display(table);
			break;

		case '4':
			write(table);
			break;

		case '5':
			read(table);
			break;

		default:
			return 0;
	}

	return 1;
}
