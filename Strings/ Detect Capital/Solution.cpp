// Problem link : https://leetcode.com/problems/detect-capital/description/
class Solution {
public:
    bool checking(string take, char s, char e) {
        for (char& ch : take) {
            if (ch < s || ch > e)
                return false;
        }
        return true;
    }

public:
    bool detectCapitalUse(string word) {
        if (checking(word, 'a', 'z') || checking(word, 'A', 'Z') ||
            checking(word.substr(1), 'a', 'z'))
            return true;
        return false;
    }
};
