#include "Message.h"
#include "Folder.h"
#include <iostream>
#include <utility>

/*
* Function move_Folders moves folders
* param Message*
* return void
*/
void Message::move_Folders(Message* m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->removeMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

/*
* Function add_to_Folders adds this Message to all Folders that point
* to the parameter
* param const Message&
* return void
*/
void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

/*
* Function remove_from_Folders removes this Message from all Folders
* in folders
* param 
* return void
*/
void Message::remove_from_Folders() {
	for (auto f : folders)
		f->removeMsg(this);
}

/*
* Copy constructor for Message
*/
Message::Message(const Message& m): contents(m.contents),
folders(m.folders) {
	add_to_Folders(m);//add this copy of Messages to the same Folders
}

/*
* Copy-assignment operator for Message
*/
Message& Message::operator=(const Message& m) {
	remove_from_Folders();//handle self-assignment
	contents = m.contents;
	folders = m.folders;
	add_to_Folders(m);
	return *this;
}

/*
* Move constructor for Message
*/
Message::Message(Message&& m) noexcept: contents(std::move(m.contents)) {
	move_Folders(&m);
}

/*
* Move-assignmet operator for Message
*/
Message& Message::operator=(Message&& rhs) noexcept {
	if (this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

/*
* Destructor for Message
*/
Message::~Message() {
	remove_from_Folders();
}

/*
* Function save adds this Message from the Folder's set of Messages
* param Folder&
* return void
*/
void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

/*
* Function remove, removes this Message from the Folder's set of Messages
* param Folder&
* return void
*/
void Message::remove(Folder& f) {
	folders.erase(&f);
	f.removeMsg(this);
}

/*
* Smaller than operator for Message
*/
bool Message::operator<(const Message& m) {
	return this->contents < m.contents;
}

/*
* Function addFolder adds Folder to folders
* param Folder*
* return void
*/
void Message::addFolder(Folder* f) {
	folders.insert(f);
}

/*
* Function removeFolder removes Folder from folders
* param Folder*
* return void
*/
void Message::removeFolder(Folder* f) {
	folders.erase(f);
}