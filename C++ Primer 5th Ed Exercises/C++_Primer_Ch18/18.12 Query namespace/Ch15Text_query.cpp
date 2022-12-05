#include "Ch15Text_query.h"
#include <sstream>

namespace Ch15 {
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

	Query_result Text_query::query(const std::string& sought) const {
		static std::shared_ptr<std::set<sz>> nodata(new std::set<sz>);
		auto loc = data.find(sought);
		if (loc == data.end())
			return Query_result(sought, nodata, file);
		else
			return Query_result(sought, loc->second, file);
	}
}

