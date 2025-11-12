// Problem Link : https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& val : mp) {
            vector<int>& take = val.second;
            int vall = INT_MAX;

            if (take.size() < 3)
                continue;

            for (int i = 0; i + 2 < take.size(); i++) {
                vall = min(vall, 2 * (take[i + 2] - take[i]));
            }

            ans = min(ans, vall);
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};
