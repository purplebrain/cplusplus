using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>

int sortedArr[8] = {4,7,12,18,23,27,33,45};
int Asize = 8;

bool
binarySearch (int idxMin, int idxMax, int k)
{
    bool retVal = false;
    int idxMid = (idxMin + idxMax)/2;
    

    if (sortedArr[idxMid] == k) {
        return true;
    } else if ((idxMin == idxMax) || (idxMid == 0) || (idxMid == (Asize-1))) {
        return false;
    } else if (k < sortedArr[idxMid]) {
        retVal = binarySearch(idxMin,(idxMid-1), k);
    } else if (k > sortedArr[idxMid]) {
        retVal = binarySearch((idxMid+1), idxMax, k);
    }

    return retVal;
}

bool searchK(int k)
{
    return binarySearch(0, 7, k);    
}

int
main (int argc, char *argv[])
{
    int inputVal;
    string inputStr;

    while(1) {
        cout << "-------------------------------" << endl;
        cout << "Enter the following : " << endl;
        cout << "find   --> to search" << endl;
        cout << "exit   --> to quit" << endl;
        cin >> inputStr;
        if (!inputStr.compare("find")) {
            cout << "Enter integer to seach in the sorted array" << endl;
            cin >> inputVal;
            if (searchK(inputVal)) {
                cout << "Input k = " << inputVal << " found in array" << endl;
            } else {
                cout << "k = " << inputVal << " not found in array" << endl;
            }
        } else if (!inputStr.compare("exit")) {
            cout << "Exiting!" << endl;
            break;
        }

        cout << endl;
    }

    return (0);
}
