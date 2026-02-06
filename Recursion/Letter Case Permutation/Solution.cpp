// Problem Link : https://leetcode.com/problems/letter-case-permutation/description/
class Solution {
public:
    vector<string> ans;
    string temp;
    void solve(int i, string s) {
        if (i == s.length()) {
            ans.push_back(temp);
            return;
        }
        if (isdigit(s[i])) {
            temp.push_back(s[i]);
            solve(i + 1, s);
            temp.pop_back();
        } else {

            temp.push_back(toupper(s[i]));
            solve(i + 1, s);
            temp.pop_back();
            temp.push_back(tolower(s[i]));
            solve(i + 1, s);
            temp.pop_back();
            
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(0, s);
        return ans;
    }
};
