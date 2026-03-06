// Problem Link : https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        vector<int> v(matrix[0].size());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1')
                    v[j] = v[j] + (matrix[i][j] - '0');
                else
                    v[j] = 0;
            }
            ans = max(ans, largestRectangleArea(v));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int ans = 0;
        int idx;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] > h[i]) {

                idx = st.top();
                st.pop();

                if (!st.empty()) {
                    ans = max(ans, h[idx] * (i - st.top() - 1));

                } else {
                    ans = max(ans, h[idx] * i);
                }
            }
            st.push(i);
        }

        while (!st.empty()) {
            idx = st.top();
            st.pop();
            if (!st.empty()) {
                ans = max(ans, h[idx] * (n - st.top() - 1));

            } else {
                ans = max(ans, h[idx] * n);
            }
        }

        return ans;
    }
};
