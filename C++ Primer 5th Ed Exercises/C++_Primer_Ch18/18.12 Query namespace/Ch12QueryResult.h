#pragma once
#include "Ch12TextQuery.h"

namespace Ch12 {
	/*
	* Class QueryResult prints contents of TextQuery
	*/
	class QueryResult {
	public:
		using sz = std::vector<std::string>::size_type;
		using set_iter = std::set<sz>::iterator;

		QueryResult(TextQuery& a) : searchWord(a.wordSought), data(a.text),
			data_map(a.text_map) {}
		void print(std::ostream& os, const std::set<sz>&);
		set_iter begin();
		set_iter end();
		std::shared_ptr<std::ifstream&> get_file();
		//or to the vector?

	private:
		std::string searchWord;
		const StrBlob& data;
		std::shared_ptr < std::map<std::string, std::set<sz>>> data_map;

	};
}

