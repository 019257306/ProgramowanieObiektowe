#include <iostream>
#include "menu.h"

int main() {
	Array* array = new Array();
	Menu menu(array);
	int choice;

	do {
		menu.print();
		choice = menu.ask();
	} while(menu.execute(choice));

	return 0;
}
