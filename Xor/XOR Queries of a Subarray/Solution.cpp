// Problem Link : https://leetcode.com/problems/xor-queries-of-a-subarray/description/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> px(n, -1);
        px[0] = arr[0];
        for (int i = 1; i < n; i++)
            px[i] = px[i - 1] ^ arr[i];

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int t = 0;
            t = px[queries[i][1]];
            if (queries[i][0] - 1 >= 0) {
                t ^= (px[queries[i][0] - 1]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
