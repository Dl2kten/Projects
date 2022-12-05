#include <iostream>
#include <vector>
#include <string>

/*
* Space and time tradeoffs
* Pre-structuring, using extra space to faciliatate faster access to data
* Simple Hash for ints to get a feeling for how it works
*/

/// <summary>
/// Meant to implement a hash table but not a true hash table as used search
/// for get and remove_key
/// </summary>
class Hash_table {
public:
	Hash_table() = default;
	Hash_table(const std::initializer_list<std::pair<unsigned, std::string>>& il): 
		table(il.size()) {
		hash_function(il);
	}
	void add(unsigned, std::string);
	std::string get(unsigned);
	bool remove_key(unsigned);
	void print();

private:
	void hash_function(std::initializer_list<std::pair<unsigned, std::string>>);
	unsigned hashing(unsigned);
	std::vector<std::pair<unsigned, std::string>> table;
};

void Hash_table::hash_function(std::initializer_list<std::pair<unsigned, 
	std::string>> p_il) {
	for (auto beg = p_il.begin(); beg != p_il.end();
		++beg) {
		auto pos = hashing(beg->first);
		//pick up here
		if (table[pos].second != "") { //handle collision with closed hashing
			for (auto i = pos + 1; i != pos; ++i) {
				if (i == table.size())
					i = 0; //reset i to search from 0 after searched to end

				if (table[i].second == "") {
					table[i] = *beg;
					break;
				}
			}

		}
		else {
			table[pos] = *beg;
		}
	}
}

/// <summary>
/// Hash function, uses mod to find the correct bucket to assign to
/// </summary>
/// <param name="p_key"></param>
/// <returns></returns>
unsigned Hash_table::hashing(unsigned p_key)
{
	unsigned h = 0;
	h = p_key % table.size();
	return h;
}

/// <summary>
/// Adds a new key-value pair to hash table
/// </summary>
/// <param name="p_key"></param>
/// <param name="p_value"></param>
void Hash_table::add(unsigned p_key, std::string p_value) {
	table.push_back({ p_key, p_value }); //this makes most sense in this
	//implementation, since only setting table to size of initializer, 
	//p_key mod table.size would give a conflict and so needs to be placed in 
	//open space which would be new space at back so might as well add it to 
	//back, if had good hash function can just add straight to new space(how
	//much space does unorder_map take to be able to add new values with O(1)?)
}

/// <summary>
/// Returns value given key
/// </summary>
/// <param name="p_key"></param>
/// <returns></returns>
std::string Hash_table::get(unsigned p_key) {
	//need to go through vector, best case O(1), worst O(n), if no collisions
	//can just put it through hash function need a really good hash function
	//for better time complexity, unordered_map
	//is Theta(1) (Theta has the highest accuracy, giving the average case?),
	//map is O(logn)
	for (const auto& i : table)
		if (i.first == p_key)
			return i.second;

	return "";
}


/// <summary>
/// Removes key-value pair based on given key
/// </summary>
/// <param name="p_key"></param>
/// <returns></returns>
bool Hash_table::remove_key(unsigned p_key)
{
	
	for(auto beg = table.begin(); beg != table.end();
		++beg) {
		if (beg->first == p_key) {
			table.erase(beg);
			return true;
		}
	}

	return false;
}

/// <summary>
/// Prints key-value pairs of hash table
/// </summary>
void Hash_table::print() {
	for (const auto& i : table)
		std::cout << i.first << "-" << i.second << "  ";
	std::cout << std::endl;
}

int main() {
	Hash_table ht{ {44, "name1"}, {12, "name2"}, {13, "name3"}, {88, "name4"},
		{23, "name5"}, {16, "name6"}, {22, "name7"} };
	ht.print();

	ht.add(54, "name8");
	ht.print();
	std::cout << ht.get(16) << std::endl;
	auto found = ht.remove_key(100);
	if (found)
		std::cout << "Removed key 100" << std::endl;
	ht.remove_key(88);
	ht.print();
	
	return 0;
}
