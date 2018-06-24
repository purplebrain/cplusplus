using namespace std;

/*
 *	CONCLUSION
 *	
 *	global 
 *		static const	-->	Read-Only, must be declared and initialized at the same time 
 *		const					-->	Read-Only, must be declared and initialized at the same time 
 *	local 
 *		static const	-->	need not be initialized when declared, but can be initialized only once 
 *		const					-->	need not be initialized when declared, but can be initialized multiple times 
 */

#include <iostream>

static const int W = 100;
const int Z = 5;

static const int w = 100;
const int z = 5;

int
sum (int a, int b)
{
	return (a + b);
}

void
foo (int a, int b)
{
		static const int x = sum(a, b);
		cout << "(foo(): local static const) X = " << x << endl;
		const int y = sum(a, b);
		cout << "(foo(): local const) Y = " << y << endl;
		//z = sum(a, b);
		//cout << "(foo() global static) Z = " << z << endl;
		//w = sum(a, b);
		//cout << "(global static const) W = " << w << endl;
	
	return;

}

int
main (int argc, char *argv[])
{
	int a, b;

	while (1) {
		cout << "Enter values of a and b" << endl;
		cout << "a : ";
		cin >> a;
		cout << "b : ";
		cin >> b;
		static const int X = sum(a, b);
		cout << "(local static const) X = " << X << endl;
		const int Y = sum(a, b);
		cout << "(local const) Y = " << Y << endl;
		//Z = sum(a, b);
		//cout << "(global static) Z = " << Z << endl;
		//W = sum(a, b);
		//cout << "(global static const) W = " << W << endl;

		foo(a, b);
	}

	return (0);
}

