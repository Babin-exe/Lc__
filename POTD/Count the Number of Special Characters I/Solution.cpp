// Problem Link : https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=daily-question&envId=2026-05-26
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> st(word.begin(), word.end());

        int ans = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            if (st.count(c) && st.count(toupper(c))) {
                ans++;
            }
        }

        return ans;
    }
};
