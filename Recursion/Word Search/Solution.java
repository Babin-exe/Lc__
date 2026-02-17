// Problem Link : https://leetcode.com/problems/word-search/
class Solution {

    private int[][] dir = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

    private boolean solve(int i, int j, char[][] board, int count, String word) {
        if (count == word.length())
            return true;

        if (i < 0 || i >= board.length || j < 0 || j >= board[0].length)
            return false;

        if (board[i][j] == '$')
            return false;

        if (board[i][j] != word.charAt(count))
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (int[] it : dir) {
            int new_i = i + it[0];
            int new_j = j + it[1];

            if (solve(new_i, new_j, board, count + 1, word)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int n = board.length;
        int m = board[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, board, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
}
