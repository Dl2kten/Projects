#include <iostream>


/*
* Exercise 16.11
* Fix text code
*/

template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>() {}
	List<elemType>(const List<elemType>&);
	List<elemType>& operator=(const List<elemType>&);
	~List() {}
	//missing template arg
	void insert(ListItem<elemType>* ptr, elemType value);
private:
	//missing template arg, and end as a pointer
	ListItem<elemType>* front, *end;
};


int main() {
	List<int> l;
	
	return 0;
}