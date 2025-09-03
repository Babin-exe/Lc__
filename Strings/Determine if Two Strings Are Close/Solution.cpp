// Problem link : https://leetcode.com/problems/determine-if-two-strings-are-close/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if (m != n)
            return false;
        vector<int> f1(26);
        vector<int> f2(26);

        for (int i = 0; i < n; i++) {
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (f1[i] == 0 && f2[i] == 0)
                continue;
            if (f1[i] != 0 && f2[i] != 0)
                continue;

            return false;
        }

        sort(begin(f1), end(f1));
        sort(begin(f2), end(f2));
        return f1 == f2;
    }
};
