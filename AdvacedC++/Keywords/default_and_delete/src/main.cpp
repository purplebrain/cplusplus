#include <iostream>
#include <type_traits>

using namespace std;

class BASE
{
	private:
		int a;
		int b;

	public:
		// SPECIAL METHODS
		BASE() =delete;
		BASE(int _a, int _b);
		BASE(const BASE& rhs) =default;
		BASE& operator=(const BASE& rhs) =default;

		// METHODS
		int getA(void) {return a;}
		int getB(void) {return b;}
		int getProductAB(void) {return a*b;}

		// FRIEND METHODS
		friend int main(int argc, char *argv[]);
};

/*
BASE::BASE()
{
	cout << "In default constructor" << endl;
}
*/

BASE::BASE(int _a, int _b) : a(_a), b(_b)
{
	cout << "In user-defined constructor" << endl;
}

int
main (int argc, char *argv[])
{
	cout << "<BASE> is default constructible : " << is_default_constructible<BASE>::value << endl;

	//BASE b1;
	//cout << "[a, b] = [" << b1.a << ", " << b1.b << "]" << endl;
	BASE b1(10, 12);

	BASE b2(3, 5);
	cout << "[a, b] = [" << b2.a << ", " << b2.b << "]" << endl;

	BASE b3(b2);
	cout << "[a, b] = [" << b3.a << ", " << b3.b << "]" << endl;

	b3 = b1;
	cout << "[a, b] = [" << b3.a << ", " << b3.b << "]" << endl;

	return (0);
}
