
#include "MySearchArrayUtils.hpp"

                    /* 
                     *  ----------------------
                     *       Binary Sort
                     *  ----------------------
                     */
/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MySearchArrayUtils::binary_search ()
 *  DESCRIPTION     This method assumes that the given array is sorted 
 *                  and searches for an element.
 * -------------------------------------------------------------------------
 */
bool
MySearchArrayUtils::binary_search_helper (int *inputArr, int idxStart, int idxEnd, int value)
{
    bool retVal = false;
    int idxMid = (idxStart + idxEnd)/2;
    
    if (value == inputArr[idxMid]) {
        return true;
    }

    if (idxEnd <= idxStart) {
        return false;
    }

    if (value < inputArr[idxMid]) {
        retVal = binary_search_helper(inputArr, idxStart, (idxMid - 1), value); 
    } 

    if (value > inputArr[idxMid]) {
        retVal = binary_search_helper(inputArr, (idxMid + 1), idxEnd, value);
    }

    return retVal;
}

/* 
 * -------------------------------------------------------------------------
 *  FUNCTION        MySearchArrayUtils::binary_search ()
 *  DESCRIPTION     This method assumes that the given array is sorted 
 *                  and searches for an element.
 * -------------------------------------------------------------------------
 */
bool
MySearchArrayUtils::binary_search (int *inputArr, int Asize, int value)
{
    bool retVal = false;
    int start = 0;
    int end = (Asize - 1);

    retVal = binary_search_helper (inputArr, start, end, value);

    return (retVal);
}
