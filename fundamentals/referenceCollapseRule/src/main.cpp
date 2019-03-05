#include <iostream>
#include <string>
#include <cstring>
#include "base.hpp"

using namespace std;

template <typename T>
void
relay(T&& arg)
{
  cout << "relay() call by reference" << endl;
  arg.printDetails();
}

template <typename T>
void
relay(T& arg)
{
  cout << "relay() call by LvalueRef" << endl;
  arg.printDetails();
}

int
main(int argc, char *argv[])
{
  // relay-call by lValue
  cout << endl;
  BASE tmpBase1(2);
  relay(tmpBase1);

  // relay-call by lValueRef
  cout << endl;
  BASE tmpBase2(4);
  BASE& refBase1 = tmpBase2;
  relay(refBase1);

  // relay-call by const lValueRef
  cout << endl;
  BASE tmpBase3(8);
  const BASE& refConstBase2 = tmpBase3;
  relay(refConstBase2);

  // relay-call by rValue
  cout << endl;
  relay(BASE(16));

  // relay-call by rValueRef
  cout << endl;
  BASE tmpBase4(BASE(32));
  relay(move(tmpBase4));

  // relay-call by const rValueRef
  cout << endl;
  const BASE&& rrefBase1 = move(BASE(16));
  relay(rrefBase1);

  cout << endl;
  return (0);
}
