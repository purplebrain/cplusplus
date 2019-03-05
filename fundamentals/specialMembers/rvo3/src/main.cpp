#include <iostream>
#include <type_traits>
#include "base.hpp"

using namespace std;

void
fooCv1 (BASE _arg)
{
  return;
}

void
fooCv2 (BASE _arg)
{
	_arg.a++;
	return;
}

int
main (int argc, char *argv[])
{
	// block-1
	// (call copy-constructor)
	{
  	g_cnt = 0;
  	BASE x;
  	fooCv1(x);
	}

	// block-2
	// (do default copy-elision)
	{
		g_cnt = 0;
		fooCv2(BASE());
	}

	// block-3
	// (prevent default copy-elision and call move-constructor)
	{
		g_cnt = 0;
		fooCv2(std::move(BASE()));
	}

	return (0);
}
