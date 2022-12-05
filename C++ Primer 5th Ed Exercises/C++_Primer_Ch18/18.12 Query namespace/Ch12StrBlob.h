#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Ch12StrVec.h"

namespace Ch12 {
	/*
	* class StrBlob for managing strings
	*/
	class StrBlob {
	public:
		using sz = std::vector<std::string>::size_type;
		friend void print(const StrBlob& s);

		StrBlob();
		StrBlob(std::initializer_list<std::string> sil);

		sz size() const { return data->size(); }
		bool empty() const { return data->empty(); }

		void push_back(const std::string& s) { data->push_back(s); }
		void pop_back();

		std::string& front();
		const std::string& front() const;
		std::string& back();
		const std::string& back() const;
		const std::string& deref(sz) const;

	private:
		std::shared_ptr<StrVec> data;
		void check(sz i, const std::string& msg) const;
	};
}

