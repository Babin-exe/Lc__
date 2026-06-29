// Problem Link : https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/?envType=daily-question&envId=2026-06-29

class Solution {
public:
    int numOfStrings(vector<string>& p, string word) {
        int n = p.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = p[i].length();
            if (l > word.length())
                continue;
            for (int v = 0; v <= word.size() - l; v++) {
                if (word.substr(v, l) == p[i]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
