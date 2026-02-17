// Problem Link : https://leetcode.com/problems/sudoku-solver/

class Solution {

    public boolean isValid(int i, int j, char[][] board, char ch) {

        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length)
            return false;

        for (int a = 0; a < 9; a++) {
            if (board[i][a] == ch)
                return false;

            if (board[a][j] == ch)
                return false;
        }

        // cell check
        int start_i = (i / 3) * 3;
        int start_j = (j / 3) * 3;

        for (int p = start_i; p < start_i + 3; p++) {
            for (int q = start_j; q < start_j + 3; q++) {
                if (board[p][q] == ch)
                    return false;
            }
        }

        return true;
    }

    public boolean solve(char[][] board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(i, j, board, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;

    }

    void solveSudoku(char[][] board) {
        solve(board);
    }
}
