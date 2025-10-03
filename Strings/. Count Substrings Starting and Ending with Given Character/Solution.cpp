// Problem Link : https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/description/

class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long hehe = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c)
                hehe++;
        }
        return (hehe * (hehe + 1) / 2);
    }
};
