#include "Text_query.h"
#include <sstream>


Text_query::Text_query(std::ifstream& is) :
	file(new std::vector<std::string>) {
	std::string text, total;
	/*
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
	*/
	while (getline(is, text)) {
		total = total + text + " ";
	}
	std::string punc_stop{ ".?!" }, punc_addition{".?!\")"};
	std::string::size_type pos = 0, pos_beg = 0;
	
	while ((pos = total.find_first_of(punc_stop, pos))
		!= std::string::npos) {
		
		if (++pos != ' ') {
		//find first not punctuation, ending of sentence could be complex
		//could be ...? ." ?! etc.
			pos = total.find_first_not_of(punc_addition,
				pos);
		}
		
		std::string word(total, pos_beg, pos - pos_beg);
		if (word[0] == ' ')
			word = word.substr(1);
		file->push_back(word);
		pos_beg = pos;
	}

	for (decltype(file->size()) i = 0; i < file->size(); ++i) {
		std::istringstream iss((*file)[i]);
		std::string word;
		while (iss >> word) {
			auto& lines = data[word];
			if (!lines)
				lines.reset(new std::set<sz>);
			lines->insert(i);
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
