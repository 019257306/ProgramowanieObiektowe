#include "menu.h"

void dataChangeMenu() {
	  int xPos;
	  int yPos;
	  int new_data;

	    cout << "Numer wiersza:" << endl;
	    cin >> yPos;
	    cout << "Numer columny:" << endl;
	    cin >> xPos;
	    cout << "new data" << endl;
	    cin >> new_data;

	    changeData(xPos, yPos, new_data);
}

void sizeChangeMenu()
{
	int new_width;
	int new_height;

	  cout << "Dlugosc:" << endl;
	  cin >> new_width;
	  cout << "Szerokosc:" << endl;
	  cin >> new_height;

	  changeSize(new_width, new_height);
}

void mainMenu()
{
	cout << "Menu:" << endl;
	cout << "1.Rozmiar" << endl;
	cout << "2.Data" << endl;
	cout << "3.Display" << endl;
	cout << "4.Write" << endl;
	cout << "5.Read" << endl;
}

bool Choice()
{
	char val;

	mainMenu();

	cout << "Enter your choice : ";
	cin >> val;

	switch(val) {
		case '1':
			sizeChangeMenu();
			break;

		case '2':
			dataChangeMenu();
			break;

		case '3':
			display();
			break;

		case '4':
			write();
			break;

		case '5':
			read();
			break;

		default:
			return 0;
	}

	return 1;
}
