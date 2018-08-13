#include <iostream>
#include <type_traits>
#include <chrono>
#include "base.hpp"

using namespace std;
using namespace std::chrono;

#define NUM_BASES 1024*64

int
main (int argc, char *argv[])
{
  auto start = high_resolution_clock::now();

  BASE arr1[NUM_BASES];
  BASE arr2[NUM_BASES];

  for (int i = 0; i < NUM_BASES; i++) {
    arr2[i] = arr1[i];
  }

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Running Time : " << duration.count() << endl;
	return (0);
}

