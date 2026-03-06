// Problem Link : https://leetcode.com/problems/daily-temperatures/description/

/*

Thought process :

Lets put index in the stack

before pushing something in stack lets try to check is the top of the stack >
something  about to be pushed

if that is so it means the right element is greater than the left  find the
difference in their index and that is the ans and push that number

but if the top value is not greater than what we are about to push than keep on
popping the top of the stack until the top > value to be pushed or the stack is
empty




*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int n = t.size();
        int i = n - 1;
        vector<int> ans(n);

        while (i >= 0) {

            while (!st.empty() && t[st.top()] <= t[i]) {
                st.pop();
            }

            if (st.empty()) {
                ans[i] = 0;
            } else {
                ans[i] = st.top() - i;
            }

            st.push(i);
            i--;
        }

        return ans;
    }
};
