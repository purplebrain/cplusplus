#include <iostream>
#include <type_traits>
#include "base.hpp"

using namespace std;

BASE
fooRv (void)
{
  return BASE();
}

int
main (int argc, char *argv[])
{
	// BLOCK-1
	{
		cout << "In BLOCK-1" << endl;
  	g_cnt = 0;
  	BASE x = fooRv();
	}

	// BLOCK-2
	{
		cout << "In BLOCK-2" << endl;
  	g_cnt = 0;
  	fooRv();
	}

	return (0);
}
