#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

/*
* Exercise 11.14
* Change program for family name to have the vector store a pair that
* holds a child's name and birthday
*/

using std::cout;
using std::cin;
using std::endl;


using childBirthday = std::vector<std::pair<std::string, std::string>>;
using familyRegister = std::map<std::string, childBirthday>;


/*
* Function addFamily adds family
* param std::map<std::string, std::<vector<std::string>>&,
* two const std::string&
* return void
*/
void addFamily(familyRegister& msv,
	const std::string& fname, const childBirthday& svec) {
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
void print(familyRegister& msv) {
	for (const auto& i : msv) {
		cout << "The family name is: " << i.first
			<< "\nThe children " << ((i.second.size() > 1) ? "names" :
				"name") << " and birthday is:";
		for (const auto& j : i.second)
			cout << "\n" << j.first << ": " << j.second;
	}
	cout << endl;
}


/*
* Function addChildren, adds children to specific families
* param std::map<std::string, std::<vector<std::string>>&,
* two const std::string&
* return void
*/
void addChildren(familyRegister& msv, const std::string& fname, 
	const std::pair<std::string, std::string>& childb) {
	auto found = msv.find(fname);
	if (found != msv.end())
		found->second.push_back(childb);
	else
		cout << "No family with last name found, create new"
		<< " family instead." << endl;
}


int main() {

	familyRegister family;
	childBirthday s{ {"Ave", "01/01"}, {"Brandon", "02/02"} };
	addFamily(family, "Adams", s);
	print(family);
	addChildren(family, "Adams", { "Crow", "04/04" });
	print(family);

	return 0;
}