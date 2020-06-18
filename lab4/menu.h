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
  void findColumnMinMenu(void);
  void findColumnMaxMenu(void);
  void findColumnMediumMenu(void);
  void findColumnSumMenu(void);
  void findRowMinMenu(void);
  void findRowMaxMenu(void);
  void findRowMediumMenu(void);
  void findRowSumMenu(void);

public:
  Menu(Array*);

/**
   * @return - menu index choice
   */

  int ask(void);					// Ask user
  void print(void);					// Print menu entries
  /**
   * @param[int] choice - menu index
   * @return - 0 if exit comment and 1 in other cases
   */
int execute(int);				// Start executing the main sequence
};


#endif
