// Problem Link : https://leetcode.com/problems/sudoku-solver/
class Solution {
public:
    bool isValid(int r, int c, vector<vector<char>>& board, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == num)
                return false;
            if (board[i][c] == num)
                return false;
        }

        int r_s = (r / 3) * 3;
        int c_s = (c / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[r_s + i][c_s + j] == num)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(i, j, board, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;

                            else {

                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
