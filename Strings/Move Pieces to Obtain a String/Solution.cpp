// Problem Link : https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        int n = start.length();
        while (i < n && j < n) {
            while (i < n && start[i] == '_')
                i++;

            while (j < n && target[j] == '_')
                j++;

            if (i == n || j == n)
                break;

            if (start[i] != target[j])
                return false;

            if (start[i] == 'L' && j > i)
                return false;

            if (start[i] == 'R' && i > j)
                return false;

            i++;
            j++;
        }

        while (i < n && start[i] == '_')
            i++;

        while (j < n && target[j] == '_')
            j++;

        return i == n && j == n;
    }
};
