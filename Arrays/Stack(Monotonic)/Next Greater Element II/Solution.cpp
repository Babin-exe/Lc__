// Problem Link : https://leetcode.com/problems/next-greater-element-ii/description/



class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);

        st.push(nums[n - 1]);

        for (int i = 2 * n - 2; i >= 0; i--) {

            int elem = nums[i % n];

            while (!st.empty() && st.top() <= elem) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i % n] = st.top();
            }
            st.push(elem);
        }

        return ans;
    }
};
