#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned int gN;
unsigned int **gArrBoard;
typedef struct POINT {
  public:
    int X;
    int Y;
    POINT (int X, int Y)
    {
      this->X = X;
      this->Y = Y;
    }
} POINT;

void
printPartialVector (vector<POINT>& vecPartial)
{
  cout << " vecPartial = [";
  for (vector<POINT>::iterator itr = vecPartial.begin();
       itr != vecPartial.end();
       itr++) {
    cout << " (" << itr->X << "," << itr->Y << ")";
  }
  cout << "]";
}

void
cleanup (void)
{
  for (int i = 0; i < gN; i++) {
    delete [] gArrBoard[i];
  }
}

void
init (void)
{
  gArrBoard = new unsigned int*[gN];
  for (int i = 0; i < gN; i++) {
    gArrBoard[i] = new unsigned int[gN];
    fill_n(gArrBoard[i], gN, 0);
  }
  return;
} 

void 
printSolution (void)
{
  cout << "########" << endl;
  for (int i = 0; i < gN; i++) {
    for (int j = 0; j < gN; j++) {
      cout << gArrBoard[i][j] << " ";
    }
    cout << endl;
  }
  cout << "########" << endl;
}

bool
isConstraintSatisfied (vector<POINT>& vecPartial) 
{
  if (vecPartial.size() == gN) {
    return (true);
  } else {
    return (false);
  }
}

bool
NQueen (int idxRow, int idxCol, vector<POINT> vecPartial)
{
	// [ EXIT CONDITION ]
  if ((idxRow == gN) || (idxCol == gN)) {
    return (true);
  } 

	// [ UPDATE PARTIALS ]
  POINT tmp(-1,-1);
  tmp.X = idxRow;
  tmp.Y = idxCol;
  vecPartial.push_back(tmp);
  gArrBoard[tmp.X][tmp.Y] = 1;

	// [ CONSTRAINT CHECK ]
  if (isConstraintSatisfied(vecPartial)) {
    // SUCCESS
    return (true); 
  } else {
    // FAILURE (go to next state)
    // CONDITION CHECK TO PICK NEXT STATE
    for (int col = 0; col < gN; col++) {
      POINT tmp(idxRow+1, col);
      bool isGood2Pick = false;
      for (int i = 0; i < vecPartial.size(); i++) {
        if (!(((vecPartial[i].X == tmp.X) || (vecPartial[i].Y == tmp.Y)) ||
              (abs(vecPartial[i].X-tmp.X) == abs(vecPartial[i].Y-tmp.Y)))) {
          isGood2Pick = true;
          continue;
        } else {
          isGood2Pick = false;
          break;
        }
      }
      if (isGood2Pick) {
        // GO TO NEXT STATE
        if (!NQueen(idxRow+1, col, vecPartial)) {
          continue;
        } else {
          return (true);
        }
      }
    }
    POINT tmp1 = vecPartial[vecPartial.size() - 1];
    vecPartial.pop_back();
    gArrBoard[tmp1.X][tmp1.Y] = 0;
    return (false);
  }
}

void 
NQueen (void)
{
  vector<POINT> vecPartial;
  // [ LOOP OVER BASE STATES ]
  for (int j = 0; j < gN; j++) {
    if (!NQueen(0, j, vecPartial)) {
      continue;
    } else {
      return;
    }
  }
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "====================================" << endl;
    cout << "Enter number of Queens : "; cin >> gN;
    init();
    NQueen();
    printSolution();
    cleanup();
  }

  return (0); 
}
