#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int globalVar1 = 0;

class BASE
{
	public:
		int a;
		int b;
	public:
		BASE(int _a, int _b) : a(_a), b(_b) {}
		~BASE() {}
		BASE& operator=(const BASE& rhs);

};

BASE&
BASE::operator=(const BASE& rhs)
{
	this->a = rhs.a;
	this->b = rhs.b;

	return (*this);
}

int
foo1 (int a)
{
	return (a);
}

int&
foo2 (int a)
{
	globalVar1 += a;
	return (globalVar1);
}

int
main (int argc, char *argv[])
{
	/*
   *	Variable name is Lvalue
   */
	cout << "Address of GlobalVar : " << &globalVar1 << endl;
	cout << "GlobalVar1 : " << globalVar1 << endl;

	/*
   *	Function name is a Lvalue
   */
	cout << "Address of function foo1 : " << &foo1 << endl;

	/*
   *	Function-call expression that returns a LvalueReference is a Lvalue
   */
	cout << "Return value of foo2 : " << foo2(5) << endl;
	cout << "Address of expr foo2(5) : " << &foo2(5) << endl;
	foo2(5) = 10;
	cout << "GlobalVar1 : " << globalVar1 << endl;
	int& k = foo2(15);

  /*
   *  Overloaded Operator expression with return type Lvalue
   */
	BASE base1(3, 4);
	BASE base2(5, 6);
	cout << "Address of overloaded operator expr : " << &(base2 = base1) << endl;
	cout << "[base2->a, base2->b] = " << "[" << base2.a << " ," << base2.b << "]" << endl;

	/*
   *	Built-in assignment expression is Lvalue
   */
	int i = 5;
	int j = 6;
	(i = j) = 10;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "Address of (i = j) is : " << &(i = j) << endl;

	/*
   *	Built-in compound assignment expression is Lvalue
   */
	int a = 5;
	int b = 6;
	(a += b) = 10;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "Address of (a += b) is : " << &(a += b) << endl;

	/*
   *	Built-in pre increment/decrement expression is Lvalue
   */ 
	int c = 5;
	--c = 10;
	cout << "c = " << c << endl;

	/*
	 *	LvalueReference 
	 *		--> can be assigned a modifiable Lvalue
   *		-->	can be assigned a non-modifiable Lvalue
   *		-->	can be modified using the above two
   */
	int z = 3;
	const int const_z = 5;
	int& x = z;
	x = const_z;

	/*
   *	const LvalueReference 
   *		--> can be assigned a modifiable Lvalue
   *		--> can be assigned a non-modifiable Lvalue
   *		--> can be assigned a Rvalue
   *		--> cannot be modified
	 */
	int p = 3;
	const int const_p = 5;
	const int& q = p;
	const int& r = const_p;
	const int& s = 10;
	const int& t = foo1(25);

	/*
   *	RvalueReference
	 *		-->	can be assigned a Rvalue only
   *		-->	can be modified using a Rvalue only
   */
	int d = 5;
	int& e = d;
	cout << "e = " << e << endl;
	const int& f = 5;
	cout << "Address of 'const int& f is : " << &f << endl;

	/*
   *	const RvalueReference
	 *		-->	can be assigned a Rvalue only
	 *		-->	cannot be modified
   */
	



	return (0);
}
