#pragma once
#include <string>
#include "Sales_data.h"

/*
* Class Token, manages copy control for union with string member
*/
class Token {
	friend std::ostream& operator<<(std::ostream&, const Token&);
public:
	Token() : tok(INT), ival{ 0 } {}
	Token(const Token&);
	Token& operator=(const Token&);
	Token(Token&&) noexcept;
	Token& operator=(Token&&) noexcept;
	~Token() {
		free_mem();
	}

	Token& operator=(const std::string&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	Token& operator=(const Sales_data&);

private:
	enum{INT, CHAR, DBL, STR, SDATA} tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data s_dval;
	};
	void copy_union(const Token&);
	void move_union(Token&&);
	void free_mem() {
		if (tok == STR)
			std::destroy_at(&sval);
		if (tok == SDATA)
			std::destroy_at(&s_dval);
	}
};

std::ostream& operator<<(std::ostream&, const Token&);