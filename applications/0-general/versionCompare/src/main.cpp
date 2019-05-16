
#include <iostream>
#include <cstddef>
#include <cstdlib>

using namespace std;

#define MAX_LEN 32

class MyQNode
{
    public:
        char data;
        MyQNode *ptrNext;

    public:
        MyQNode (char value) {
            this->data = value;
            this->ptrNext = NULL;
        }
};

class MyQ
{
    public:
        int Qsize;
        MyQNode *ptrHead;
        MyQNode *ptrTail;

    public:
        MyQ ()
        {
            this->Qsize = 0;
            this->ptrHead = NULL;
            this->ptrTail = NULL;
        }

        int
        getSize () 
        {
            return (this->Qsize);
        }

        void
        enque (char data) {
            if (this->Qsize == 0) {
                MyQNode *ptrQNode = new MyQNode(data);
                this->ptrHead = ptrQNode;
                this->ptrTail = ptrQNode;
            } else {
                MyQNode *ptrQNodeTmp = this->ptrTail;
                this->ptrTail = new MyQNode(data);
                this->ptrTail->ptrNext = ptrQNodeTmp;
            }
            this->Qsize++;
            return;
        }

        char
        deque()
        {
            if (this->Qsize == 0) {
                return ('x');
            }

            MyQNode *ptrQNodeRet = this->ptrTail;
            this->ptrTail = this->ptrTail->ptrNext;
            this->Qsize--;

            return (ptrQNodeRet->data);
        }
};

MyQ qV1;
MyQ qV2;

int
version_cmp(char *v1, char *v2)
{
    int idx1 = 0, idx2 = 0;
    int retVal = 0;

    //while ((v1[idx1] != '\0') || (v2[idx2] != '\0')) {
    while (1) {
        
        while (!(((v1[idx1] == '.') || (v1[idx1] == '\0'))
                 && 
                 ((v2[idx2] == '.') || (v2[idx2] == '\0')))) {

            if (v1[idx1] != '.') {
                qV1.enque(v1[idx1]);
                idx1++;
            }
            if (v2[idx2] != '.') {
                qV2.enque(v2[idx2]);
                idx2++;
            }
        }

        if (qV1.getSize() > qV2.getSize()) {
            return (1);
        } else if (qV1.getSize() < qV2.getSize()) {
            return (-1);
        } else {
            // queues sizes are equal, it means strings are of equal length
            while (qV1.getSize()) {
                char v1_char = qV1.deque();
                char v2_char = qV2.deque();
                if (v1_char > v2_char) {
                    return (1);
                } else if (v1_char < v2_char) {
                    return (-1);
                } else {
                    // if chars are equal, continue comparing the rest of the string
                    continue;
                }
            }
        }

        // If here, then it means the strings were equal so far
        if ((v1[idx1] == '\0') && (v2[idx2] == '\0')) {
            return (0);
        } else if (v1[idx1] == '\0') {
            return (-1);
        } else if (v2[idx2] == '\0') {
            return (1);
        }

        idx1++;
        idx2++;
    }

    return retVal;
}


int
main (int argc, char *argv[]) 
{
    int retVal;

    char ver1[MAX_LEN];
    char ver2[MAX_LEN];

    cout << "Enter version string #1 : ";
    cin >> ver1;
    cout << "Enter version string #2 : ";
    cin >> ver2;

    retVal = version_cmp(ver1, ver2);

    if (retVal == 0) {
        cout << "ver1 equal to ver2" << endl;
    } else {
        if (retVal > 0) {
            cout << "ver1 greater than ver2" << endl;
        } else {
            cout << "ver1 less than ver2" << endl;
        }
    }

    return (0);
}
