#include <iostream>
#include "menu.h"

int main() {
	Menu<int, std::string, std::string> menu;
	int choice;

	do {
		menu.print();
		choice = menu.ask();
	} while(menu.execute(choice));

	return 0;
}
