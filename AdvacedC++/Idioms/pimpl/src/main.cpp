#include <iostream>
#include <string>
#include <cstring>
#include "base.hpp"

using namespace std;

int
main(int argc, char *argv[])
{
  cout << endl;
  BASE b(5);
  b.printGrp();
  
  cout << endl;
  BASE x;
  x = b;
  x.printGrp();

  cout << endl;
  return (0);
}
