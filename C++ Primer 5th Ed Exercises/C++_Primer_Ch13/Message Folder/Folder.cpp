#include "Folder.h"
#include <iostream>

/*
* Function add_to_Messages adds this Folder to the Messages pointed at
* by the parameter
* param const Folder&
* return void
*/
void Folder::add_to_Messages(const Folder& f) {
	for (auto m : f.messages)
		m->addFolder(this);
}

/*
* Function remove_from_Messages removes this Folder from the Messages 
* param 
* return void
*/
void Folder::remove_from_Messages() {
	for (auto m : messages)
		m->removeFolder(this);
}

/*
* Copy constructor for Folder
*/
Folder::Folder(const Folder& f): messages(f.messages) {
	add_to_Messages(f);
}

/*
* Copy-assignment operator for Folder
*/
Folder& Folder::operator=(const Folder& f) {
	remove_from_Messages();
	messages = f.messages;
	add_to_Messages(f);
	return *this;
}

/*
* Destructor for Folder
*/
Folder::~Folder() {
	remove_from_Messages();
}

/*
* Function addMsg, adds the parameter to messages
* param Message*
* return void
*/
void Folder::addMsg(Message* m) {
	messages.insert(m);
}

/*
* Function removeMsg, removes the parameter from messages
* param Message*
* return void
*/
void Folder::removeMsg(Message* m) {
	messages.erase(m);
}

/*
* Function print, prints out Messages from set
* param ostream&
* return void
*/
void Folder::print(std::ostream& os) {
	os << "The messages contained in Folder " << folder_name
		<< ":\n";
	for (const auto i : messages)
		os << i->contents << " ";
	os << std::endl;
}