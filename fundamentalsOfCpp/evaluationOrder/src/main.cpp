#include <iostream>

using namespace std;

int
foo (int _x) {
	_x += 15;
	cout << __PRETTY_FUNCTION__ << "x = " << _x << endl;
	return (_x);
}

int
bar (int _y) {
	_y -= 15;
	cout << __PRETTY_FUNCTION__ << "y = " << _y << endl;
	return (_y);
}

int
foo_eval (int _a, int _b)
{
	cout << __PRETTY_FUNCTION__ << "a = " << _a << endl;
	cout << __PRETTY_FUNCTION__ << "b = " << _b << endl;
	return (_a + _b);
}

int
main (int argc, char *argv[])
{
	int val = foo_eval(foo(5), bar(5));
	cout << __PRETTY_FUNCTION__ << "val = " << val << endl;
	return (0);
}
