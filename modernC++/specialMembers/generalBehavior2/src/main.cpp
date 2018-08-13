#include <iostream>
#include <type_traits>
#include "base.hpp"

using namespace std;

BASE&
foo(BASE& base)
{
	cout << "call by lValueRef, return lValueRef" << endl;
	return (base);
}

BASE&
foo(BASE&& base)
{
	cout << "call by rValueRef, return lValueRef" << endl;
	return (base);
}

BASE&
bar(BASE& base)
{
	cout << "bar() entry" << endl;
	base = BASE(5);
	cout << "bar() exit" << endl;
	return (base);
}

BASE
gum(void)
{
	cout << "entry gum()" << endl;
	//BASE x = BASE(5);
	cout << "exit gum()" << endl;
	//return (move(x));
	return (BASE(10));
}

int
main (int argc, char *argv[])
{
	// 1
	cout << endl;
	cout << "< 1 >" << endl;
	BASE a;
	a.printGrp();

	// 2
	cout << endl;
	cout << "< 2 >" << endl;
	BASE b(8);
	b.printGrp();

	// 3
	cout << endl;
	cout << "< 3 >" << endl;
	BASE(8).printGrp();

	// 4
	cout << endl;
	cout << "< 4 >" << endl;
	foo(BASE(4)).printGrp();

	// 5
	cout << endl;
	cout << "< 5 >" << endl;
	foo(b).printGrp();

	// 6 (??)
	cout << endl;
	cout << "< 6 >" << endl;
	BASE z = BASE(4);
	z.printGrp();

	// 7
	cout << endl;
	cout << "< 7 >" << endl;
	BASE x = foo(b);
	x.printGrp();

	// 8
	cout << endl;
	cout << "< 8 >" << endl;
	BASE y = move(foo(b));
	y.printGrp();

	// 9
	cout << endl;
	cout << "< 9 >" << endl;
	BASE r = BASE(3); // This is same as --> BASE r(3);
	r = bar(r);
	r.printGrp();

	// 10
	cout << endl;
	cout << "< 10 >" << endl;
	BASE&& nRef = move(BASE(5)); // At the end of this expression, 
															 // destructor will be called. But
															 //	it has no effect, since the object
															 // is already moved.
	nRef.printGrp();

	// 11
	cout << endl;
	cout << "< 11 >" << endl;
	BASE m(gum());	//	This is as good as 
									//	BASE m(BASE(10)) i.e. m(10)
	m.printGrp();

	// 12
	cout << endl;
	cout << "< 12 >" << endl;
	return (0);
}
