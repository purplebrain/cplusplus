/*
    [ PROBLEM STATEMENT ]
    The knight is placed on the first block of an empty board and, 
    moving according to the rules of chess, must visit each square exactly once.
 */

#include <iostream>
#include <vector>

using namespace std;

#define ROWS 8
#define COLS 8
#define FULL_BOARD ROWS*COLS

typedef struct POINT {
  public:
    int m_X;
    int m_Y;
    int m_MoveNum;
  public:
    POINT (void)
    {
      this->m_X = -1;
      this->m_Y = -1;
      this->m_MoveNum = 0;
    }
    POINT (int X, int Y)
    {
      this->m_X = X;
      this->m_Y = Y;
      this->m_MoveNum = 0;
    }
} POINT;

string gCmd;
int gMoves;
int **gArrBoard;
POINT gStartingPoint;
vector<POINT> gMoveTemplate;

void
cleanup (void)
{
  for (int i = 0; i < ROWS; i++) {
    delete [] gArrBoard[i];
  }
}

void
init (void)
{
  gMoves = 0;
  gArrBoard = new int*[ROWS];
  for (int i = 0; i < COLS; i++) {
    gArrBoard[i] = new int[COLS];
  }
  
  POINT AdjustFactor;
  // Template #0
  AdjustFactor.m_X = -1;
  AdjustFactor.m_Y = 2;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #1
  AdjustFactor.m_X = 1;
  AdjustFactor.m_Y = 2;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #2
  AdjustFactor.m_X = -2;
  AdjustFactor.m_Y = 1;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #3
  AdjustFactor.m_X = -2;
  AdjustFactor.m_Y = -1;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #4
  AdjustFactor.m_X = -1;
  AdjustFactor.m_Y = -2;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #5
  AdjustFactor.m_X = 1;
  AdjustFactor.m_Y = -2;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #6
  AdjustFactor.m_X = 2;
  AdjustFactor.m_Y = -1;
  gMoveTemplate.push_back(AdjustFactor);
  // Template #7
  AdjustFactor.m_X = 2;
  AdjustFactor.m_Y = 1;
  gMoveTemplate.push_back(AdjustFactor);
  
  if ((gStartingPoint.m_X == -1) && (gStartingPoint.m_Y == -1)) {
    gStartingPoint.m_X = 0;
    gStartingPoint.m_Y = 0;
    gStartingPoint.m_MoveNum = 1;
    gMoves++;
  } 
  
  return;
}

void
PrintSolution (void)
{
  cout << "########################" << endl;
  for (int x = 0; x < ROWS; x++) {
    for (int y = 0; y < COLS; y++) {
      cout << gArrBoard[x][y] << " ";
    }
    cout << endl;
  }
  cout << "########################" << endl;
}

void
PopulatePartials (POINT& CurPoint, vector<POINT>& vecPartial)
{
  for (int i = 0; i < gMoveTemplate.size(); i++) {
    POINT tmp;
    tmp.m_X = CurPoint.m_X + gMoveTemplate[i].m_X;
    tmp.m_Y = CurPoint.m_Y + gMoveTemplate[i].m_Y;
    if ((tmp.m_X < 0) || (tmp.m_X >= COLS)) {
      continue;
    } 
    if ((tmp.m_Y < 0) || (tmp.m_Y >= ROWS)) {
      continue;
    }
    cout << "DEBUG : picked template-" << i << endl;
    vecPartial.push_back(tmp);
  }
  return;
}

bool
isConstraintSatisfied (POINT& CurPoint, POINT& NextPoint)
{
  bool retVal = true;

  if (CurPoint.m_MoveNum >= FULL_BOARD) {
    return (false);
  }

  if (gArrBoard[NextPoint.m_X][NextPoint.m_Y]) {
    return (false);
  } 

  return (retVal);
}

bool
KnightTour (POINT CurPoint, POINT NextPoint) 
{
  cout << "DEBUG : STACK (X,Y) " 
       << "(" << NextPoint.m_X << "," << NextPoint.m_Y << ")" << endl;
	// [ EXIT CONDITION ]
  if (CurPoint.m_MoveNum == FULL_BOARD) {
    return (true);
  }

	// [ UPDATE PARTIALS ]
  vector<POINT> vecPartial;
  PopulatePartials(NextPoint, vecPartial);

	// [ CONSTRAINT CHECK ]
  if (isConstraintSatisfied(CurPoint, NextPoint)) {
		// proceed further
    gArrBoard[NextPoint.m_X][NextPoint.m_Y] = CurPoint.m_MoveNum + 1;
    gMoves++;
  } else {
    return (false);
  }

  for (vector<POINT>::iterator itr = vecPartial.begin(); itr != vecPartial.end(); itr++) {
    if (!KnightTour(NextPoint, *itr)) {
      cout << "DEBUG : Back to STACK (X,Y) " << "(" << NextPoint.m_X << "," << NextPoint.m_Y << ")" << endl;
      continue;
    } else {
      return (true);
    }
  }

  gArrBoard[NextPoint.m_X][NextPoint.m_Y] = 0;
  gMoves--;
  return (false);
}

void
KnightTour (void)
{
  // [ LOOP OVER BASE STATES ]
  for (int idxRow = 0; idxRow < ROWS; idxRow++) {
    for (int idxCol = 0; idxCol < COLS; idxCol++) {
      vector<POINT> vecPartial;
      POINT ptTmp(idxRow, idxCol);
      PopulatePartials(ptTmp, vecPartial);
      for (vector<POINT>::iterator itr = vecPartial.begin(); 
          itr != vecPartial.end(); 
          itr++) {
        cout << "DEBUG : BASE_STACK (X,Y) " 
             << "(" << ptTmp.m_X << "," << ptTmp.m_Y << ")" << endl;
        if (!KnightTour(ptTmp, *itr)) {
          cout << "DEBUG : Back to BASE_STACK (X,Y) " 
               << "(" << ptTmp.m_X << "," << ptTmp.m_Y << ")" << endl;
          continue;
        } else {
          return;
        }
      }
    }
  }
}

int
main (int argc, char *argv[])
{
  while (1) {
    cout << endl;
    cout << "Continue? yes/no : ";
    cin >> gCmd;
    if (!gCmd.compare("no")) {
      return (0);
    }
    init();
    KnightTour();
    if (gMoves == FULL_BOARD) {
        PrintSolution();
    } else {
        cout << "No solution" << endl;
    }
    cleanup();
  }

  return (0);
}
