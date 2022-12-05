#include "TextQuery.h"
#include <sstream>
#include <string>
#include <tuple>

using sz = std::vector<std::string>::size_type;
using tuple_result = std::tuple<const std::string&,
	std::shared_ptr<std::set<sz>>,
	std::shared_ptr<std::vector<std::string>>>;

Text_query::Text_query(std::ifstream& is) :
	file(new std::vector<std::string>) {
	std::string text;

	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream iss(text);
		std::string word;
		while (iss >> word) {
			auto& lines = data[word];
			if (!lines)
				lines.reset(new std::set<sz>);
			lines->insert(n);
		}
	}
}

tuple_result Text_query::query(const std::string& sought) const {
	static std::shared_ptr<std::set<sz>> nodata(new std::set<sz>);
	auto loc = data.find(sought);
	if (loc == data.end())
		return std::make_tuple(sought, nodata, file);
	else
		return std::make_tuple(sought, loc->second, file);
}