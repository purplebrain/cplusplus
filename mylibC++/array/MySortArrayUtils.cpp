
#include "MySortArrayUtils.hpp"

                    /* 
                     *  ----------------------
                     *      Selection Sort
                     *  ----------------------
                     */
void 
MySortArrayUtils::selection_sort  (int *inputArr, int Asize)
{
    int idxPick;
    int idxSmall;;

    for (int i = 0; i < Asize; i++) {
        idxPick = i;
        idxSmall = idxPick;
        for (int p = (idxPick + 1); p < Asize; p++) {
            if (inputArr[p] < inputArr[idxSmall]) {
                idxSmall = p;
            }
        }
        if (idxSmall != idxPick) {
            // swap 
            int tmp = inputArr[idxPick];
            inputArr[idxPick] = inputArr[idxSmall];
            inputArr[idxSmall] = tmp;
        }
    }
}

                    /* 
                     *  ----------------------
                     *        Merge Sort
                     *  ----------------------
                     */
void
MySortArrayUtils::merge_sort_conquer (int inputArr[], int idxLeft, int idxMid, int idxRight)
{
    int range1 = (idxMid - idxLeft + 1);
    int range2 = (idxRight - idxLeft);
    int tmpArrLeft[range1];
    int tmpArrRight[range2];
    int idxArr = idxLeft;
    int i = 0;
    int j = 0;

    for (i=0;i<range1;i++) {
        tmpArrLeft[i] = inputArr[idxLeft + i];
    }

    for (j=0;j<range2;j++) {
        tmpArrRight[j] = inputArr[idxMid + 1 + j];
    }

    i = 0;
    j = 0;

    while ((i < range1) && (j < range2)) {
        if (tmpArrLeft[i] <= tmpArrRight[j]) {
            inputArr[idxArr] = tmpArrLeft[i];
            i++;
        } else if (tmpArrLeft[i] >= tmpArrRight[j]) {
            inputArr[idxArr] = tmpArrRight[j];
            j++;
        }
        idxArr++;
    }

    while (i < range1) {
        inputArr[idxArr] = tmpArrLeft[i];
        idxArr++;
        i++;
    }

    while (j < range2) {
        inputArr[idxArr] = tmpArrRight[j];
        idxArr++;
        j++;
    }
}

void
MySortArrayUtils::merge_sort_divide (int inputArr[], int idxLeft, int idxRight)
{
    int mid;

    if (idxLeft < idxRight) {
        mid = (idxRight + idxLeft)/2;
        merge_sort_divide(inputArr, idxLeft, mid);
        merge_sort_divide(inputArr, (mid + 1), idxRight);
        merge_sort_conquer(inputArr, idxLeft, mid, idxRight);
    }
}

void 
MySortArrayUtils::merge_sort (int inputArr[], int Asize)
{
    int idxLeft = 0;
    int idxRight = (Asize - 1);

    merge_sort_divide(inputArr, idxLeft, idxRight);
}
