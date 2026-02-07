// Problem Link : https://leetcode.com/problems/n-queens/

class Solution {
    List<List<String>> ans = new ArrayList<>();
    int N;

    public boolean isValid(List<String> board, int row, int col) {

        for (int i = row - 1; i >= 0; i--) {
            String curr = board.get(i);
            char[] arr = curr.toCharArray();
            if (arr[col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            String curr = board.get(i);
            char[] arr = curr.toCharArray();
            if (arr[j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            String curr = board.get(i);
            char[] arr = curr.toCharArray();
            if (arr[j] == 'Q')
                return false;
        }

        return true;

    }

    public void solve(ArrayList<String> board, int row) {
        if (row >= N) {
            ans.add(new ArrayList<>(board));
            return;
        }

        for (int col = 0; col < N; col++) {

            if (isValid(board, row, col)) {

                String curr = board.get(row);
                char[] arr = curr.toCharArray();
                arr[col] = 'Q';
                board.set(row, new String(arr));
                solve(board, row + 1);
                arr[col] = '.';
                board.set(row, new String(arr));
            }
        }

    }

    public List<List<String>> solveNQueens(int n) {
        String row = ".".repeat(n);
        ArrayList<String> board = new ArrayList<>(Collections.nCopies(n, row));
        N = n;
        solve(board, 0);
        return ans;
    }
}
