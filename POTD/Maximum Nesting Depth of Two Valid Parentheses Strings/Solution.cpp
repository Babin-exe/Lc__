// Problem Link : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int val = 0;
        int n = seq.length();
        for (int i = 0; i < n; ++i) {
            char ch = seq[i];
            if (ch == '(') {
                ans.push_back(val % 2);
                val++;
            } else {
                val--;
                ans.push_back(val % 2);
            }
        }
        return ans;
    }
};
