// Problem Link : https://leetcode.com/problems/adding-spaces-to-a-string/description/

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        string ans;
        int i = 0;
        while (i < s.length()) {
            if (j < spaces.size() && i == spaces[j]) {
                ans += ' ';
                j++;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};
