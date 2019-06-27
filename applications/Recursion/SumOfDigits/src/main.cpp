/*
 *  < PROBLEM DESCRIPTION >
 *	Find the sum of the digits in a given number
 */

#include <iostream>
#include <math>

using namespace std;

int
getNextDigit(int N, int pow)
{
	int divisor = pow(10, pow);

	// BASE CONDITION
	if (!(N/divisor)) {
		 return (N % divisor);
	}

	// MANDATORY CONDITION
	getNextDigit	

}
