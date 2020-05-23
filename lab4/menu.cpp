#include "menu.h"

Menu::Menu(Array* new_array) {
	array = new_array;
}

void Menu::findColumnMinMenu(void) {
	int column;

	cout << "Enter the number of a column : ";
	cin >> column;

	array->findColumnMin(column);
}

void Menu::findColumnMaxMenu(void) {
	int column;

	cout << "Enter the number of a column : ";
	cin >> column;

	array->findColumnMax(column);
}

void Menu::findColumnMediumMenu(void) {
	int column;

	cout << "Enter the number of a column : ";
	cin >> column;

	array->findColumnMedium(column);
}

void Menu::findRowMinMenu(void) {
	int row;

	cout << "Enter the number of a column : ";
	cin >> row;

	array->findRowMin(row);
}

void Menu::findRowMaxMenu(void) {
	int row;

	cout << "Enter the number of a column : ";
	cin >> row;

	array->findRowMax(row);
}

void Menu::findRowMediumMenu(void) {
	int row;

	cout << "Enter the number of a column : ";
	cin >> row;

	array->findRowMedium(row);
}

void Menu::findColumnSumMenu(void) {
	int column;

	cout << "Enter the number of a column : ";
	cin >> column;

	array->findColumnSum(column);
}

void Menu::findRowSumMenu(void) {
	int row;

	cout << "Enter the number of a row : ";
	cin >> row;

	array->findRowSum(row);
}

void Menu::dataChangeMenu(void) {
	  int xPos,					// Position in a row
	  		yPos,				// Position in a collumn
	  		new_data;			// New data

	  cout << "Row number : ";
	  cin >> yPos;
	  cout << "Column number : ";
	  cin >> xPos;
	  cout << "New data in the cell : ";
	  cin >> new_data;

		// Ask user about new values
	  array->changeData(xPos, yPos, new_data);
}

void Menu::sizeChangeMenu(void) {
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

void Menu::print(void) {
	cout << endl;
	cout << "========= MENU =========" << endl;
	cout << "0.Exit the program" << endl;
	cout << "1.Change size (initial)" << endl;
	cout << "2.Change data of a specific cell" << endl;
	cout << "3.Display the array" << endl;
	cout << "4.Write data into a file" << endl;
	cout << "5.Read data from the file" << endl;
	cout << "6.Find column's min" << endl;
	cout << "7.Find column's max" << endl;
	cout << "8.Find column's medium" << endl;
	cout << "9.Find rows's min" << endl;
	cout << "10.Find row's max" << endl;
	cout << "11.Find row's medium" << endl;
	cout << "12.Find sum of the column" << endl;
	cout << "13.Find sum of the row" << endl;
	cout << endl;
}

int Menu::ask(void) {
	int choice;								// Temporary variable to store user's choice

	// Commad prompt
	cout << "Enter your choice : ";
	cin >> choice;

	return choice;
}

int Menu::execute(int choice) {
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

		case 6:
			findColumnMinMenu();
			break;

		case 7:
			findColumnMaxMenu();
			break;

		case 8:
			findColumnMediumMenu();
			break;

		case 9:
			findRowMinMenu();
			break;

		case 10:
			findRowMaxMenu();
			break;

		case 11:
			findRowMediumMenu();
			break;

		case 12:
			findColumnSumMenu();
			break;

		case 13:
			findRowSumMenu();
			break;
	}

	return 1;
}
