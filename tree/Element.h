#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

enum types
{
	integer,
	floating,
	character,
	undefined
};

class Element
{
public:
	~Element();
	Element();
	double& operator = (double dval);
	int& operator = (int cval);
	string& operator = (string sval);
	size_t get_type();
	int get_ivalue();
	double get_dvalue();
	string get_svalue();
	template< typename Ty1 >
	void add_elem(Ty1 Pa1);
private:
	types type;
	union
	{
		int ivalue;
		double dvalue;
		string svalue = "\0";
	};
};


template<typename Ty1>
void Element::add_elem(Ty1 Pa1)
{
	this->operator=(Pa1);
}