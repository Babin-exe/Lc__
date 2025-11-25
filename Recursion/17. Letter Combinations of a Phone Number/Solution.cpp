Problem Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/


class Solution {
public:
    vector<string> ans;
    vector<vector<char>> hehe = {
        {}, {},
        {'a','b','c'}, {'d','e','f'}, {'g','h','i'},
        {'j','k','l'}, {'m','n','o'}, {'p','q','r','s'},
        {'t','u','v'}, {'w','x','y','z'}
    };
    
    void solve(string &digits, int idx, string temp) {
        if(temp.length() == digits.length()) {
            ans.push_back(temp);
            return;
        }
        if(idx == digits.length()) return;

        int num = digits[idx] - '0';

        for(int i = 0; i < hehe[num].size(); i++) {
            char ch = hehe[num][i];
            solve(digits, idx + 1, temp + ch);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string temp = "";
        solve(digits, 0, temp);
        return ans;
    }
};
