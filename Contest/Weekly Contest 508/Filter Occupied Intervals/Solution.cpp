// Problem Link : https://leetcode.com/problems/filter-occupied-intervals/
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& o,
                                                int freeStart, int freeEnd) {

        sort(o.begin(), o.end());
        vector<vector<int>> merged;
        for (auto& it : o) {
            if (merged.empty() || merged.back()[1] < it[0] - 1) {
                merged.push_back(it);
            } else {
                merged.back()[1] = max(merged.back()[1], it[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto& it : merged) {
            int l = it[0];
            int r = it[1];

            if (l < freeStart) {
                ans.push_back({l, min(r, freeStart - 1)});
            }

            if (r > freeEnd) {
                ans.push_back({max(freeEnd + 1, l), r});
            }
        }

        return ans;
    }
};
