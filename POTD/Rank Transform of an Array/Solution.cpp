// Problem Link: https://leetcode.com/problems/rank-transform-of-an-array/?envType=daily-question&envId=2026-07-12

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if (n == 0)
            return {};

        vector<int> temp = arr;
        sort(begin(temp), end(temp));

        map<int, int> mp;
        mp[temp[0]] = 1;

        int curr = 1;

        for (int i = 1; i < n; i++) {
            if (temp[i] == temp[i - 1]) {
                mp[temp[i]] = curr;
            } else {
                curr++;
                mp[temp[i]] = curr;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};
