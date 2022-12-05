#include "Token.h"
#include <iostream>

/// <summary>
/// copy constructor call private utility function
/// </summary>
/// <param name="t"></param>
Token::Token(const Token& t)
{
	copy_union(t);
	tok = t.tok;
}

/// <summary>
/// move constructor call private move utility function
/// </summary>
/// <param name="t"></param>
Token::Token(Token&& t) noexcept
{
	std::cout << "move constructor" << std::endl;
	move_union(std::move(t));
	tok = t.tok;
}

/// <summary>
/// 
/// </summary>
/// <param name="t"></param>
/// <returns></returns>
Token& Token::operator=(Token&& t) noexcept
{
	std::cout << "move assign" << std::endl;

	if (tok != STR && tok != SDATA)
		move_union(std::move(t));
	else {
		if (tok == STR) {
			if (t.tok == STR) {
				sval = std::move(t.sval);
			}
			else {
				std::destroy_at(&sval);
				move_union(std::move(t));
			}
		} //end of if(tok == STR)
		if (tok == SDATA) {
			if (t.tok == SDATA)
				s_dval = std::move(t.s_dval);
			else {
				std::destroy_at(&s_dval);
				copy_union(std::move(t));
			}
		}
	}
	tok = t.tok;


	return *this;
}

/// <summary>
/// copy assignment, takes into account three cases
/// </summary>
/// <param name="t"></param>
/// <returns></returns>
Token& Token::operator=(const Token& t)
{
	if (tok != STR && tok != SDATA)
		copy_union(t);
	else {
		if (tok == STR) {
			if (t.tok == STR)
				sval = t.sval;
			else {
				std::destroy_at(&sval);
				copy_union(t);
			}
		} //end of if(tok == STR)
		if (tok == SDATA) {
			if (t.tok == SDATA)
				s_dval = t.s_dval;
			else {
				std::destroy_at(&s_dval);
				copy_union(t);
			}
		}
	}
	tok = t.tok;

	
	return *this;
}


/// <summary>
/// operator= taking string
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
Token& Token::operator=(const std::string& s)
{
	if (tok == STR)
		sval = s;
	else {
		if (tok == SDATA)
			std::destroy_at(&s_dval);
		new(&sval) std::string(s);
	}
	tok = STR;
	return *this;
}

/// <summary>
/// operator= for char
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
Token& Token::operator=(char c)
{
	free_mem();
	cval = c;
	tok = CHAR;
	return *this;
}

/// <summary>
/// operator= for int
/// </summary>
/// <param name="i"></param>
/// <returns></returns>
Token& Token::operator=(int i)
{
	free_mem();
	ival = i;
	tok = INT;
	return *this;
}

/// <summary>
/// operator= for double
/// </summary>
/// <param name="d"></param>
/// <returns></returns>
Token& Token::operator=(double d)
{
	free_mem();
	dval = d;
	tok = DBL;
	return *this;
}

/// <summary>
/// operator= for Sales_data
/// </summary>
/// <param name="sd"></param>
/// <returns></returns>
Token& Token::operator=(const Sales_data& sd)
{
	if (tok == SDATA)
		s_dval = sd;
	else {
		if (tok == STR)
			std::destroy_at(&sval);
		new(&s_dval) Sales_data(sd);
	}
	tok = SDATA;
	return *this;
}

/// <summary>
/// private utility function to assign correct union member
/// </summary>
/// <param name=""></param>
void Token::copy_union(const Token& t)
{
	switch (t.tok) {
	case Token::INT:
		ival = t.ival;
		break;
	case Token::CHAR:
		cval = t.cval;
		break;
	case Token::DBL:
		dval = t.dval;
		break;
	case Token::STR:
		new(&sval) std::string(t.sval);
		break;
	case Token::SDATA:
		new(&s_dval) Sales_data(t.s_dval);
	default:
		break;
	}
}

/// <summary>
/// private utility for move operations
/// </summary>
/// <param name="t"></param>
void Token::move_union(Token&& t)
{
	switch (t.tok) {
	case Token::INT:
		ival = t.ival;
		break;
	case Token::CHAR:
		cval = t.cval;
		break;
	case Token::DBL:
		dval = t.dval;
		break;
	case Token::STR:
		new(&sval) std::string(std::move(t.sval));
		break;
	case Token::SDATA:
		new(&s_dval) Sales_data(std::move(t.s_dval));
	default:
		break;
	}
}

std::ostream& operator<<(std::ostream& os, const Token& t)
{
	switch (t.tok) {
	case Token::INT:
		os << t.ival << std::endl;
		break;
	case Token::CHAR:
		os << t.cval << std::endl;
		break;
	case Token::DBL:
		os << t.dval << std::endl;
		break;
	case Token::STR:
		os << t.sval << std::endl;
		break;
	case Token::SDATA:
		os << t.s_dval << std::endl;
		break;
	default:
		break;
	}

	return os;
}
