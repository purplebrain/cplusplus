using namespace std;

#include <iostream>
#include <cstdlib>
#include <cstddef>

int
findRoot_in_InOrderArr (int *arrInOrder, int rootVal, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arrInOrder[i] == rootVal) {
            return i;
        }
    }

    return (-1);
}

void
printPostOrder(int *arrInOrder, int *arrPreOrder, int length)
{
    int idxRoot = findRoot_in_InOrderArr(arrInOrder, arrPreOrder[0], length);

    if (idxRoot != 0) {
        printPostOrder(arrInOrder, arrPreOrder+1, idxRoot);
    }

    if (idxRoot != (length - 1)) {
        printPostOrder(arrInOrder+idxRoot+1, arrPreOrder+idxRoot+1,((length-1)-idxRoot));
    }

    cout << arrPreOrder[0] << " ";
}

int
main (int argc, char *argv[])
{
    int arrInOrder[6] = {8, 7, 3, 5, 10, 4};
    int arrPreOrder[6] = {5, 7, 8, 3, 10, 4};

    printPostOrder(arrInOrder, arrPreOrder, 6);

    cout << endl;

    return (0);
}
