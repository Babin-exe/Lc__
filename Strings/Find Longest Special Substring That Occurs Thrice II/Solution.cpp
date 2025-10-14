// Problem Link : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/

class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> hehe(26, vector<int>(n + 1, 0));

        char prev = s[0];
        int length = 0;

        for (int i = 0; i < n; i++) {
            char curr = s[i];
            int row = curr - 'a';
            if (curr == prev) {
                length++;
                hehe[row][length] += 1;
            } else {
                length = 1;
                hehe[row][length] += 1;
                prev = curr;
            }
        }

        int ans = -1;

        for (int i = 0; i < 26; i++) {
            int sum = 0;
            for (int j = n; j >= 1; j--) {
                sum += hehe[i][j];
                if (sum >= 3) {
                    ans = max(ans, j);
                    break;
                }
            }
        }

        return ans;
    }
};


class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> hehe(26, vector<int>(n + 1, 0));

        char prev = s[0];
        int length = 0;

        for (int i = 0; i < n; i++) {
            char curr = s[i];
            int row = curr - 'a';
            if (curr == prev) {
                length++;
                hehe[row][length] += 1;
            } else {
                length = 1;
                hehe[row][length] += 1;
                prev = curr;
            }
        }

        int ans = -1;

        for (int i = 0; i < 26; i++) {
            int sum = 0;
            for (int j = n; j >= 1; j--) {
                sum += hehe[i][j];
                if (sum >= 3) {
                    ans = max(ans, j);
                    break;
                }
            }
        }

        return ans;
    }
};
