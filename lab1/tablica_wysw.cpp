#include <iostream>
#include <stdlib.h>
#include <vector>
#include "table.h"
 
int main()
{
	std::vector<std::vector<int>> table{{1,2,3},
		                            {1,2,3},
					    {1,2,3}};
	 Table::changeData(table,0,0,100);
	 Table::display(table);
	 return 0;
}
