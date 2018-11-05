#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int
main (int argc, char *argv[])
{
	int *ptr = NULL;
	int x = 10;

	ptr = &(--x);
	x = 15;
	cout << "ptr points to : " << *ptr << endl;
	cout << "x : " << x << endl;

	return (0);
}
