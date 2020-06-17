#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "table.h"

using namespace std;

bool run(void);                   // Start executing the main sequence
void mainMenu(void);              // Print menu entries
void sizeChangeMenu(Table&);      // Change size submenu
void dataChangeMenu(Table&);      // Change data submenu

#endif
