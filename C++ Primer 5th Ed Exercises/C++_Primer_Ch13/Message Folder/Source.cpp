#include "Message.h"
#include "Folder.h"
#include <iostream>
#include <vector>
#include <algorithm>

/*
* Funciton swap, swaps two Message obj
* param two Message&
* return void
*/
inline void swap(Message& lhs, Message& rhs) {
	using std::swap;
	std::cout << "Swap" << std::endl;
	for (auto f : lhs.folders)
		f->removeMsg(&lhs);
	for (auto f : rhs.folders)
		f->removeMsg(&rhs);

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
	//better to just remove and readd
}

int main() {

	Folder inbox("Inbox");
	Folder junk("Junk");

	Message m1("hello", "m1"), m2("hi"), m3("howdy"), m4("junk1"), m5("junk2"),
		m6("junk3", "m6");

	m1.save(inbox);
	m2.save(inbox);
	m3.save(inbox);
	m4.save(junk);//ok to save multiple times as stored in set
	m5.save(junk);
	m6.save(junk);

	inbox.print(std::cout);
	junk.print(std::cout);

	Message m7(m1), m8;
	m8 = m6;
	inbox.print(std::cout);
	junk.print(std::cout);

	m8.remove(junk);
	m8.remove(inbox);//nothin happens
	m2.remove(inbox);
	inbox.print(std::cout);
	junk.print(std::cout);

	swap(m1, m6);
	inbox.print(std::cout);
	junk.print(std::cout);

	/*
	* added a second constructor to Message for debugging check that
	* the swap actually swapped variables, swap is meant for more 
	* efficient algorithmic operation implementations not really for
	* user to use
	*/
	return 0;
}