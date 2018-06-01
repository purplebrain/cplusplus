using namespace std;
/*
 *  < PROBLEM DESCRIPTION >
 *  Generate the sum of first N numbers using recursion
 *
 */

#include <csignal>
#include <cstdio>
#include <iostream>

unsigned long long *memoize_fibonacci;

int
countOfNDigit (int pos_avail, int sum_left)
{
    int count = 0;
    
    if (pos_avail) {
        if (sum_left == 0) {
            return (1); // remaining positions can be filled with '0'
        } else if (sum_left < 0) {
            return (0); // all parts of 'sum' is consumed
        } else {
            // continue
        }
    } else {
        if (sum_left == 0) {
            return (1);
        } else if (sum_left < 0) {
            return (0);
        } else {
            return (0);
        }
    }

    for (int i = 0; i <= 9; i++) {
        count = count + countOfNDigit(pos_avail - 1, sum_left - i);
    }

    return count;
}

unsigned long long
fibonacci_dp (int N)
{
    unsigned long long sequenceNum;
 
    if (memoize_fibonacci[N] != 0) {
        return memoize_fibonacci[N];
    }

    if ((N == 0) || (N == 1))
        return 1;

    sequenceNum = fibonacci_dp(N-1) + fibonacci_dp(N-2); 

    memoize_fibonacci[N] = sequenceNum;
    return sequenceNum;
}

int
fibonacci (int N)
{
    int sequenceNum;

    if (N < 0) {
        return 0;
    }

    if ((N == 0) || (N == 1))
        return 1;

    sequenceNum = fibonacci(N-1) + fibonacci(N-2); 

    return sequenceNum;
}

int
factorial (int N)
{
    int result;

    if (N == 0) {
        return 1;
    }

    result = N*factorial(N-1);

    return result;
}

int
sumOfN (int N)
{
    int sum;

    if (N == 0) {
        return (0);
    }

    sum = N + sumOfN(N-1); 

    return sum;
}

int
fooNumOfRecursion_v2 (int N)
{
    int recursion = 0;
    
    if (N == 0) {
        return (0);
    }

    recursion += fooNumOfRecursion_v2(N-1);

    return recursion;
}

int
fooNumOfRecursion (int N)
{
    int recursion;

    if (N == 0) {
        return (0);
    }

    recursion = 1 + fooNumOfRecursion(N-1); 

    return recursion;
}

int 
main (int argc, char *argv[])
{
    int inputChoice, inputNumber;
    unsigned long long result;
    bool isExit = false;

    while (1) {
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Pick an option : " << endl;
        cout << "1) Verify N recursions" << endl;
        cout << "2) Find sum of N consecutive numbers" << endl;
        cout << "3) Get Nth number in fibonacci sequence" << endl;
        cout << "4) Get Nth number in fibonacci sequence using DP" << endl;
        cout << "5) Get factorial of N" << endl;
        cout << "6) Count of N-digit numbers with SUM" << endl;
        cout << "7) Verify N recursions of return value added to itself" << endl;
        cout << "-1 to Quit" << endl;
        cin >> inputChoice;
        switch (inputChoice) {
        case -1:
            isExit = true;
            break;
        case 1:
            result = 0;
            cout << "Enter value for N : ";
            cin >> inputNumber;
            result = fooNumOfRecursion(inputNumber);
            break;
        case 2:
            result = 0;
            cout << "Enter value for N : ";
            cin >> inputNumber;
            result = sumOfN(inputNumber);
            break;
        case 3:
            cout << "Enter value for N : ";
            cin >> inputNumber;
            result = fibonacci(inputNumber);
            break;
        case 4:
            result = 0;
            cout << "Enter value for N : ";
            cin >> inputNumber;
            memoize_fibonacci = new unsigned long long[inputNumber];
            fill(memoize_fibonacci, memoize_fibonacci+sizeof(unsigned long long)*inputNumber, 0);
            result = fibonacci_dp(inputNumber);
            break;
        case 5:
            cout << "Enter value for N : ";
            cin >> inputNumber;
            cout << "Factorial of N : ";
            result = factorial(inputNumber);
            break;
        case 6:
            result = 0;
            int N, SUM;
            cout << "Enter value of N : ";
            cin >> N;
            cout << "Enter value of SUM : ";
            cin >> SUM;
            for (int i = 1; i <= 9; i++) {
                if (SUM-i >= 0) {
                    result = result + countOfNDigit(N-1, SUM-i);
                }
            }
            break;
        case 7:
            cout << "Enter value for N : ";
            cin >> inputNumber;
            result = fooNumOfRecursion_v2(inputNumber);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        
        cout << "Result = " << result << endl;
        
        if (isExit) {
            break;
        }
    }

    return (0);
}
