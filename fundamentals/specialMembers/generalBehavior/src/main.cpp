#include <iostream>
#include <type_traits>
#include "base.hpp"

using namespace std;

BASE gVar1(16, "lemon");

BASE
bar_lvalRef_lval(BASE& base)
{
	cout << "call by lValueRef, return lValue" << endl;
	base = BASE(4, "tmp_bar_lvalRef_value");
	return (base);
}

BASE
bar_void_lval(void)
{
	cout << "call void, return by lValue" << endl;
	BASE x = BASE(2, "apple");

  x = BASE(2, "mango");
	BASE y = x;

  x = BASE(2, "pear");
	BASE z = x;

  y = z;

	return (y);
}

void
bar_lval_lval0(BASE x)
{
	cout << "call by lValue, return void" << endl;
	return;
}

BASE
bar_lval_lval1(BASE x)
{
	cout << "call by lValue, return by lValue" << endl;
	return (x);
}

BASE
bar_lval_lval2(BASE x)
{
	cout << "call by lValue, return by lValue" << endl;
	return (BASE(8, "tmp_bar_lval_lval2"));
}

BASE
bar_lval_lval3(void)
{
  cout << "call void, return by lValue" << endl;
  return (move(gVar1));
}

BASE&
foo_lvalRef_lvalRef(BASE& base)
{
	cout << "call by lValueRef, return lValueRef" << endl;
	return (base);
}

BASE&
foo_rvalRef_lvalRef(BASE&& base)
{
	cout << "call by rValueRef, return lValueRef" << endl;
	return (base);
}

BASE&&
foo_lvalRef_rvalRef(BASE& base)
{
	cout << "call by lValueRef, return rValueRef" << endl;
	return (move(base));
}

BASE&&
foo_rvalRef_rvalRef(BASE&& base)
{
	cout << "call by rValueRef, return rValueRef" << endl;
	return (move(base));
}

int
main (int argc, char *argv[])
{
	// 1
	cout << endl;
	cout << "< 1 >" << endl;
	BASE a(4, "A");
	a.printGrp();

	// 2
	cout << endl;
	cout << "< 2 >" << endl;
	BASE b(2, "B");
	b.printGrp();

	// 3
	cout << endl;
	cout << "< 3 >" << endl;
	BASE(4, "tmp3").printGrp();

	// 4
	cout << endl;
	cout << "< 4 >" << endl;
	bar_void_lval().printGrp();

	// 4.5
	cout << endl;
	cout << "< 4.5 >" << endl;
	bar_lval_lval0(BASE(8, "tmp4.5"));

	// 5
	cout << endl;
	cout << "< 5 >" << endl;
	bar_lval_lval1(BASE(8, "tmp5")).printGrp();

	// 6
	cout << endl;
	cout << "< 6 >" << endl;
	BASE c(BASE(8, "tmp6"));
	bar_lval_lval1(c).printGrp();

	// 7
	cout << endl;
	cout << "< 7 >" << endl;
	BASE d = bar_lval_lval1(BASE(8, "tmp7"));
	d.printGrp();

	// 8
	cout << endl;
	cout << "< 8 >" << endl;
	BASE e = bar_lval_lval2(BASE(8, "tmp8"));
	e.printGrp();

	// 9
	cout << endl;
	cout << "< 9 >" << endl;
	BASE f = bar_lval_lval3();
	f.printGrp();
	gVar1.printGrp();

	// End
	cout << endl;
	cout << "< End >" << endl;
	return (0);
}
