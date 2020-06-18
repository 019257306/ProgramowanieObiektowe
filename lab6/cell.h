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

/**
 * @return - data in the cell
 */
template <class Type>
Type Cell<Type>::getData(void) { return data; }

/**
 * @param[Type] value - new internal value of the cell of a variable type
 */
template <class Type>
void Cell<Type>::setData(Type value) { data = value; }

/**
 * @param[std::ostream&] os - output stream
 * @param[Cell<Type>&] object - link to the cell instance
 * @return - stream with data from the cell written
 */
template <class Type>
std::ostream& operator<<(std::ostream& os, const Cell<Type>& object) {
	os << object.data;

   return os;
}

#endif	//CELL_H
