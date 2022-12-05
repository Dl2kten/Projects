#include<iostream>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

/*
* Exercise 11.7
* Define a map for which the key is the family's last name and the value
* is a vector of the children's names, write code to add new families and
* to add new children to an existing family
*/

using std::cout;
using std::cin;
using std::endl;

/*
* Function addFamily adds family
* param std::map<std::string, std::<vector<std::string>>&,
* two const std::string&
* return void
*/
void addFamily(std::map<std::string, std::vector<std::string>>& msv,
	const std::string& fname, const std::vector<std::string>& svec) {
	/*std::vector<std::string> svec;
	std::string names, lastName, firstName;
	//user prompt
	cout << "Enter the family name followed by the names of the "
		<< "children:\n";
	getline(cin, names);
	std::istringstream iss(names);
	iss >> lastName;
	while (iss >> firstName)
		svec.push_back(firstName);
	*/
	msv.insert({ fname, svec });
}


/*
* Function print, prints out contents of map
* param std::map<std::string, std::<vector<std::string>>&
* return void
*/
void print(std::map<std::string, std::vector<std::string>>& msv) {
	for (const auto& i : msv) {
		cout << "The family name is: " << i.first
			<< "\nThe children " << ((i.second.size() > 1) ? "names" :
				"name") << " are:";
		for (const auto& j : i.second)
			cout << " " << j;
	}
	cout << endl;
}


/*
* Function addChildren, adds children to specific families
* param std::map<std::string, std::<vector<std::string>>&, 
* two const std::string&
* return void 
*/
void addChildren(std::map<std::string, std::vector<std::string>>& msv,
	const std::string& fname, const std::string& cname) {
	auto found = msv.find(fname);
	if (found != msv.end())
		found->second.push_back(cname);
	else
		cout << "No family with last name found, create new"
		<< " family instead." << endl;
}


int main() {

	std::map < std::string, std::vector<std::string>> family;
	std::vector<std::string> s{ "Ave", "Brandon" };
	addFamily(family, "Adams", s);
	print(family);
	addChildren(family, "Adams", "Crow");
	print(family);

	return 0;

	/*
	* can do typedef for the map, check for redundancies in family name 
	*/
}