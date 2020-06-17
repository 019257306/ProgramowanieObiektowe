#ifndef CELL_H
#define CELL_H

#include <iostream>

template <class Type>
class Cell final {
private:
	Type data;

public:
	Type getData(void);
	void setData(Type);

	template <typename SecondType>
	friend std::ostream& operator<<( std::ostream&, const Cell<SecondType>& );
};

template <class Type>
Type Cell<Type>::getData(void) { return data; }

template <class Type>
void Cell<Type>::setData(Type value) {
	std::cout << value << std::endl;
	
	data = value;
}

template <class Type>
std::ostream& operator<<(std::ostream& os, const Cell<Type>& object) {
	os << object.data;

    return os;
}

#endif	//CELL_H
