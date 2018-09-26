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
  g_cnt = 0;
  BASE x = fooRv();

  g_cnt = 0;
  fooRv();

	return (0);
}
