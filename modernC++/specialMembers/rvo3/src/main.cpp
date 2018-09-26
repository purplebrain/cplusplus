#include <iostream>
#include <type_traits>
#include "base.hpp"

using namespace std;

void
fooCv (BASE _arg1)
{
  return;
}

int
main (int argc, char *argv[])
{
	// block-1
	{
  	g_cnt = 0;
  	BASE x;
  	fooCv(x);
	}

	// block-2
	{
		g_cnt = 0;
		fooCv(BASE());
	}

	return (0);
}
