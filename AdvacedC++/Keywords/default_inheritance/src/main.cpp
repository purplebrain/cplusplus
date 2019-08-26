#include <iostream>
#include <type_traits>

using namespace std;

class BASE
{
	public:
		int a;
		int b;
};

class DERIVED : public BASE
{
	private:
		int c;
	public:
		DERIVED(int _a, int _b);
		int getC(void);
};

DERIVED::DERIVED(int _a, int _b)
{
	this->c = _a + _b;
}

int
DERIVED::getC(void)
{
	return (this->c);
}

int
main (int argc, char *argv[])
{
	cout << "<BASE> is default constructible : " << is_default_constructible<BASE>::value << endl;
	cout << "<DERIVED> is default constructible : " << is_default_constructible<DERIVED>::value << endl;

	DERIVED d1(3, 5);

	cout << "DERIVED->c : " << d1.getC() << endl;

	return (0);
}
