#include <iostream>
#include <cstring>
#include <string>

#include "base.hpp"

using namespace std;

BASE&
BASE::operator=(const BASE& rhs)
{
	this->a = rhs.a;
	this->b = rhs.b;

	return (*this);
}

