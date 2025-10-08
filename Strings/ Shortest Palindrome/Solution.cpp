// Problem Link : https://leetcode.com/problems/shortest-palindrome/

class Solution {
    void makeLps(const string& str, vector<int>& LPS) {
        LPS[0] = 0;
        int length = 0;
        int n = str.length();
        int i = 1;

        while (i < n) {
            if (str[i] == str[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length == 0) {
                    LPS[i] = 0;
                    i++;
                } else {
                    length = LPS[length - 1];
                }
            }
        }
    }

public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + "^" + rev;
        vector<int> LPS(str.length());

        makeLps(str, LPS);
        int index = rev.length() - LPS[str.length() - 1];

        return rev.substr(0, index) + s;
    }
};
