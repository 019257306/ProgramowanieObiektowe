#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "table.h"

using namespace std;

/**
 * @return - 0 if program should stop being executed
 */
bool run(void);                   // Start executing the main sequence
void mainMenu(void);              // Print menu entries

/**
 * @param[Table] table - link to a struct
 */
void sizeChangeMenu(Table&);      // Change size submenu

/**
 * @param[Table] table - link to a struct
 */
void dataChangeMenu(Table&);      // Change data submenu

#endif
