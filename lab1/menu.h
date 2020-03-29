#ifndef Menu_h
#define Menu_h

   #include <iostream>
#include "table.h"

  using namespace std;
    std::vector<std::vector<int>> table{{1,2,3},
	                                {1,2,3},
					{1,2,3}};

  class Menu
{
	public:
		static bool Choice();
		static void mainMenu();
		static void sizeChangeMenu();
		static void dataChangeMenu();
};
  
  void Menu::dataChangeMenu()
{
	  int xPos;
	  int yPos;
	  int new_data;

	    cout << "Numer wiersza:" << endl;
	    cin >> yPos;
	    cout << "Numer columny:" << endl;
	    cin >> xPos;
	    cout << "new data" << endl;
	    cin >> new_data;

	      Table::changeData(table, xPos, yPos, new_data);
}

   void Menu::sizeChangeMenu()
{
	int new_width;
	int new_height;

	  cout << "Dlugosc:" << endl;
	  cin >> new_width;
	  cout << "Szerokosc:" << endl;
	  cin >> new_height;

	  Table::changeSize(table, new_width, new_height);
}

 void Menu::mainMenu()
{
	 cout << "Menu:" << endl;
	 cout << "1.Rozmiar" << endl;
	 cout << "2.Data" << endl;
	 cout << "3.Display" << endl;
}

bool Menu::Choice()
{
	char val;

	  Menu::mainMenu();

	  cin >> val;
	  switch(val)
	  {
		  case '1':
			  Menu::sizeChangeMenu();
			  break;

		  case '2':
			  Menu::dataChangeMenu();
			  break;

		  case '3':
			  Table::display(table);
			  break;

		  default:
			  return 1;
break;
	  }
	  return 1;
}
#endif

