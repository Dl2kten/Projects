#pragma once
#include <string>
#include <set>

class Folder;

class Message {
	friend class Folder;
	friend void swap(Message&, Message&);
public:
	explicit Message(const std::string& s = "") : contents(s) {}
	Message(const std::string& s1, const std::string& s2) :
		contents(s1), variable_name(s2) {}
	Message(const Message&);
	Message& operator=(const Message&);
	Message(Message&&) noexcept;
	Message& operator=(Message&&) noexcept;
	bool operator<(const Message&);
	~Message();

	//add/remove this Message from the Folder's set of Messages
	void save(Folder&);
	void remove(Folder&);
	const std::string& get_contents() const { return contents; }
	
private:
	std::string contents;
	std::string variable_name;
	std::set<Folder*> folders;

	void move_Folders(Message* m);
	void addFolder(Folder*);
	void removeFolder(Folder*);
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};