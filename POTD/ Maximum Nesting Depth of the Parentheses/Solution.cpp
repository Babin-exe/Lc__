// Problem Link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int count = 0;
        int hehe = 0;
        for (char ch : s) {
            if (ch == '(') {
                hehe++;
                count = max(count, hehe);
            } else if (ch == ')') {
                hehe--;
            }
        }
        return count;
    }
};
