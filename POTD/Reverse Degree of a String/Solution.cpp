// Problem Link : https://leetcode.com/problems/reverse-degree-of-a-string/description/
class Solution {
public:
    map<char, int> mp;

    int reverseDegree(string s) {
        for (int i = 0; i < 26; ++i) {
            mp['a' + i] = 26 - i;
        }
        
        int c = 1;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int val = mp[s[i]];
            ans = ans + (val * c);
            c++;
        }
        return ans;
    }
};
