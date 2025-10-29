// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/

class Solution {
    public char kthCharacter(long k, int[] operations) {
        if (k == 1)
            return 'a';

        long len = 1;
        int ops = -1;
        long hehe = 0;
        int n = operations.length;
        for (int i = 0; i < n; i++) {
            len *= 2;
            if (len >= k) {
                ops = operations[i];
                hehe = k - len / 2;
                break;
            }
        }

        char ch = kthCharacter(hehe, operations);
        if (ops == 0)
            return ch;

        if (ch == 'z')
            return 'a';

        return ((char) ((int) ch + 1));

    }
}


