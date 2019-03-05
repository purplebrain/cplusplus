#ifndef _BASE_HPP
#define _BASE_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <type_traits>
#include <typeinfo>

using namespace std;

class BASE
{
	private:
		int c;
	public:
    string name;
		int a;
		int b;
	public:
    // constructors
		BASE(string _name);
		BASE(string _name, int _a, int _b);

    // destructor
    ~BASE();

    // copy-semantics
		BASE(const BASE& rhs);
		BASE& operator=(const BASE& rhs);

    // move-semantics
		BASE(BASE&& rhs);
		BASE& operator=(BASE&& rhs);

    // operators
    BASE& operator+(const BASE& rhs);

    // other methods
    void printABC(void);
    int getC(void);
};

#endif
