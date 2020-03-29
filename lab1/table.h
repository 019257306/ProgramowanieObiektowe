#ifndef Table_h
#define Table_h

 #include <iostream>
  #include <vector>

  struct tab
{
	int x;
	int y;
}Tab;

class Table
{
	public:
	static void changeSize(std::vector<std::vector<int>> table, int new_width, int new_height);
	static void changeData(std::vector<std::vector<int>> table, int xPos, int yPos, int new_data);
	static void display(std::vector<std::vector<int>> table);
};

   void Table::display(std::vector<std::vector<int>> table)
{
	for(int i = 0; i<table.size(); i++)
	{
		for(int j = 0; j<table[i].size(); j++)
		{
			std::cout << table[i][j];
			std::cout << " ";
		}
		std::cout << std::endl;
	}

}

   void Table::changeData(std::vector<std::vector<int>> table, int xPos , int yPos, int new_data)
{
	if (table.size() > 0)
	{
		if(yPos>table.size() || xPos > table[0].size())
		{
			std::cout << "Niepoprawna wartosc" << std::endl;
		} else{
			table.at(yPos).at(xPos) = new_data;
		}
	}
}

  void Table::changeSize(std::vector<std::vector<int>> table, int new_width, int new_height)
{
	table.resize(new_height);

	for(int i =0; i<table.size(); i++)
	{
		table[i].resize(new_width);
	}
}
#endif
