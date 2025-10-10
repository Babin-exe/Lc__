// Problem Link: https://leetcode.com/problems/string-compression-iii/

class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string ans;
        for (int i = 0; i < n;) {
            char ch = word[i];
            int count = 0;
            while (i < n && ch == word[i] && count < 9) {
                count++;
                i++;
            }
            ans += to_string(count);
            ans += ch;
        }
        return ans;
    }
};
