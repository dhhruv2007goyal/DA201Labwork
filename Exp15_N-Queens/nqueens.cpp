//Dhhruv Goyal 25/A07/019

#include <iostream>
#include <vector>
using namespace std;

int N;

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        // Same column
        if (board[i] == col)
            return false;

        // Same diagonal
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

bool solveNQueens(vector<int>& board, int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solveNQueens(board, row + 1))
                return true;

            // Backtrack
            board[row] = -1;
        }
    }

    return false;
}

int main() {
    cout << "Enter number of queens: ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid board size.\n";
        return 0;
    }

    vector<int> board(N, -1);

    if (solveNQueens(board, 0)) {
        cout << "One solution:\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i] == j)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << '\n';
        }
    } else {
        cout << "No solution exists for N = " << N << '\n';
    }

    return 0;
}