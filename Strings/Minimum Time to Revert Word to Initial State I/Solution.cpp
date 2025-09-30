// Problem link : https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/description/



class Solution {

public:
    bool check(string& word, int i) {
        return word.substr(i) == word.substr(0, word.size() - i);
    }

public:
    int minimumTimeToInitialState(string word, int k) {
        int i = k;
        int count = 1;
        while (i < word.length()) {
            if (check(word, i)) {
                break;
            } else {
                i += k;
                count++;
            }
        }
        return count;
    }
};
