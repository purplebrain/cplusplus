#include<iostream>
#include<string>
#include<boost/multiprecision/cpp_int.hpp>
#include<chrono>

using namespace std::chrono;
using namespace boost::multiprecision;
using namespace std;

#define EXEC_TYPE_ITR 1
#define EXEC_TYPE_REC 2
#define EXEC_TYPE_DP 3

/* Fibonacci Series Calculated Iteratively */
int1024_t fibonacci_iterative(int1024_t num)
{
	int i, j;
	int1024_t fib, fib_0 = 0, fib_1 = 1;
	
	/* Base condition for checking an out of bound number */
	if ((num < 0) || (num > 100)) {
		cout << "The number is out of bounds! \nPlease provide a  number between 0 amd 100 \n";
		return(-1);
	}

	if (num == 0)
		return (0);

	if(num == 1)
		return (1);

	for (i=2; i<=num; i++) {
		fib = fib_0 + fib_1;
		fib_0 = fib_1;
		fib_1 = fib;
	}

	return(fib);
}

/* Fibonacci Series Calculated Recursively */
int1024_t fibonacci_recursive(int1024_t num)
{
	int i, j;
	int1024_t fib;
	
	/* Base condition for checking an out of bound number */
	if ((num < 0) || (num > 100)) {
		cout << "The number is out of bounds! \nPlease provide a  number between 0 amd 100 \n";
		return(-1);
	}

	/* Base condition for checking Fibonacci number num = 0/num = 1 */
	if (num == 0)
		return (0);

	if (num == 1)
		return (1);
	
	/* Fib(num) = Fib(num-1) + Fib(num-2) */
	return(fibonacci_recursive(num-1) + fibonacci_recursive(num-2));
}

/* Fibonacci Series Calculated via Dynamic Programming */
int1024_t fibonacci_dp(int1024_t num, int1024_t fib_0, int1024_t fib_1)
{
	int i, j;
	int1024_t fib;
	
	/* Base condition for checking an out of bound number */
	if ((num < 0) || (num > 100)) {
		cout << "The number is out of bounds! \nPlease provide a  number between 0 amd 100 \n";
		return(-1);
	}
	
	if (num == 0)
		return fib_0;
	
	/* Fib(num) = Fib(num-1) + Fib(num-2) */
	return(fibonacci_dp(num-1, fib_1, fib_1+fib_0));
}

int1024_t fibonacci_dp_helper(int1024_t num)
{
	/* Base condition for checking an out of bound number */
	if ((num < 0) || (num > 100)) {
		cout << "The number is out of bounds! \nPlease provide a  number between 0 amd 100 \n";
		return(-1);
	}

	return(fibonacci_dp(num, 0, 1));
}

int 
main(int argc, char *argv[])
{
	int num, type;

  while (1) {
    cout << endl;
    cout << "==================" << endl;
    cout << "Enter value for N" << endl;
    cout << "N = "; 
		cin >> num;
    cout << "Enter execution type [1:Itr, 2:Rec, 3:DP]";
		cout << "Type = ";
		cin >> type;

		switch (type) {
		case EXEC_TYPE_ITR:
			auto start_it= high_resolution_clock::now();
			cout << "The fibonacci number for n: " << num << " = "  << fibonacci_iterative(num) << endl;
			auto stop_it = high_resolution_clock::now();
			auto duration_it = duration_cast<microseconds>(stop_it - start_it);
			cout << "Time taken by iterative function = " << " = " << duration_it.count() << " microseconds" << endl << endl;
			break;
		case EXEC_TYPE_REC:
			auto start_rec = high_resolution_clock::now();
			cout << "The fibonacci number for n: " << num << " = " << fibonacci_recursive(num) << endl;
			auto stop_rec = high_resolution_clock::now();
			auto duration_rec = duration_cast<microseconds>(stop_rec - start_rec);
			cout << "Time taken by recursive function = " << duration_rec.count() << " microseconds" << endl << endl;
			break;
		case EXEC_TYPE_DP:
			auto start_dp = high_resolution_clock::now();
			cout << "The fibonacci number for n: " << num <<  " = " << fibonacci_dp_helper(num) << endl;
			auto stop_dp = high_resolution_clock::now();
			auto duration_dp = duration_cast<microseconds>(stop_dp - start_dp);
			cout << "Time taken by Dynamic Programming function = " << duration_dp.count() << " microseconds" << endl << endl;
			break;
		default:
			break;
		}
	}

	return (0);
}
