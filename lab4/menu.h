#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "array.h"

using namespace std;

class Menu {
private:
  Array* array;

  void sizeChangeMenu(void);      // Change size submenu
  void dataChangeMenu(void);      // Change data submenu

public:
  Menu(Array*);

  char ask(void);					// Ask user
  void print(void);					// Print menu entries
  int execute(char);				// Start executing the main sequence
};


#endif
