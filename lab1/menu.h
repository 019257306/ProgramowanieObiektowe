#ifndef Menu_h
#define Menu_h

#include <iostream>
#include "table.h"

using namespace std;

/**
 * @return - 0 if program should stop being executed
 */
bool run(void);
void mainMenu(void);

/**
 * @param[int**&] table - 2D array
 * @param[int&] rows - amount of rows in the array
 * @param[int&] columns - amount of columns in the array
 */
void sizeChangeMenu(int**&, int&, int&);

/**
 * @param[int**&] table - 2D array
 * @param[int&] rows - amount of rows in the array
 * @param[int&] columns - amount of columns in the array
 */
void dataChangeMenu(int**, int&, int&);

#endif
