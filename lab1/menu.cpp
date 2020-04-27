#include "menu.h"

void dataChangeMenu(int** table, int &rows, int &columns) {
	  int xPos;
	  int yPos;
	  int new_data;

	    cout << "Numer wiersza:" << endl;
	    cin >> yPos;
	    cout << "Numer columny:" << endl;
	    cin >> xPos;
	    cout << "new data" << endl;
	    cin >> new_data;

	    changeData(table, rows, columns, xPos, yPos, new_data);
}

void sizeChangeMenu(Table& table_str)
{
	int new_width;
	int new_height;

	  cout << "Dlugosc:" << endl;
	  cin >> new_width;
	  cout << "Szerokosc:" << endl;
	  cin >> new_height;

	  changeSize(table, rows, columns, new_width, new_height);
}

void mainMenu(void)
{
	cout << "Menu:" << endl;
	cout << "1.Rozmiar" << endl;
	cout << "2.Data" << endl;
	cout << "3.Display" << endl;
	cout << "4.Write" << endl;
	cout << "5.Read" << endl;
}

bool run(void) {
	// TO DELETE
	static int** table = nullptr;
	static int rows = 0, columns = 0;
	char val;

	mainMenu();

	cout << "Enter your choice : ";
	cin >> val;

	switch(val) {
		case '1':
			sizeChangeMenu(table, rows, columns);
			break;

		case '2':
			dataChangeMenu(table, rows, columns);
			break;

		case '3':
			display(table, rows, columns);
			break;

		case '4':
			write(table, rows, columns);
			break;

		case '5':
			read(table, rows, columns);
			break;

		default:
			return 0;
	}

	return 1;
}
