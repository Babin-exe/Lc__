// Problem Link : https://leetcode.com/problems/word-search/description/
class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    bool solve(int i, int j, vector<vector<char>>& board, int count,
               string word) {

        if (count == word.length())
            return true;

        if (i < 0 || i >= board.size() || j >= board[0].size() || j < 0) {
            return false;
        }

        if (board[i][j] == '$')
            return false;

        if (board[i][j] != word[count])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& it : dir) {
            int new_i = i + it[0];
            int new_j = j + it[1];

            if (solve(new_i, new_j, board, count + 1, word)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int count = 0;
                if (solve(i, j, board, count, word))
                    return true;
            }
        }

        return false;
    }
};
