#include<iostream>

using namespace std;

class A
{
	private:
		int x;
	public:
		void 
		setX(int i) 
		{
			x = i;
		}

		void 
		print(void) 
		{ 
			cout << x << endl; 
		}
};

class B: virtual public A
{
	public:
		B() 
		{ 
			setX(10); 
		}
};

class C: virtual public A 
{
	public:
		C() 
		{ 
			setX(20); 
		}
};

class D: public C, public B 
{

};

int 
main(int argc, char *argv[])
{
	D d;
	d.print();

	return 0;
}
