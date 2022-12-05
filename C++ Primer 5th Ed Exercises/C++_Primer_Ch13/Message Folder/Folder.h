#pragma once
#include "Message.h"

class Folder {
public:
	friend class Message;
	Folder(const std::string s = ""): folder_name(s) {}
	Folder(const Folder& f);
	Folder& operator=(const Folder& f);
	~Folder();

	void addMsg(Message*);
	void removeMsg(Message*);
	void print(std::ostream&);
private:
	std::string folder_name;
	std::set<Message*> messages;

	
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
};
