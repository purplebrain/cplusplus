#include <iostream>

using namespace std;

int gN;
int **board;

bool
helper (int board[], int i)
{
  if (i == N) {
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        if (col == row) {
            cout << "0" << endl;
        } else {
            cout << "X" << endl;
        }
      }
      cout << endl;
    }
    return (true);
  }

  for (int col = 0; col < N; col++) {
    bool flag = false;
    for (int row = 0; row < i; row++) {
      if (board[row] == col || abs(board[row] - col) == (i - row)) {
        flag = true;
        break;
      }
    }
    if (flag) {
      continue;
    }
    board[i] = col;
    if (helper(board, i+1)) {
      return (true);
    }
  }

  return (false);
}

int
main (int argc, char *argv[])
{
	cout << "Enter the value of N = ";
	cin >> N;

	// INITIALIZE THE BOARD
	for (int i = 0; i < N; i++) {
		board[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = 0;
		}
	}

  helper(board, 0);
	
  return (0);
}
