#include "Element.h"

Element::Element()
{
	type = undefined;
}

Element::~Element()
{
}



double& Element::operator= (double dval)
{
	type = floating;
	dvalue = dval;
	return dvalue;
}
int& Element::operator= (int ival)
{
	type = integer;
	ivalue = ival;
	return ivalue;
}

string& Element::operator= (string sval)
{
	type = character;
	svalue = sval;
	return svalue;
}

size_t Element::get_type()
{
	return this->type;
}

int Element::get_ivalue()
{
	return this->ivalue;
}

double Element::get_dvalue()
{
	return dvalue;
}

string Element::get_svalue()
{
	return svalue;
}



