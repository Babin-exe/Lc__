// Problem Link : https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;
    int sum = 0;
    void solve(int i, vector<int>& candidates, int target) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }

        if (sum > target || i == candidates.size()) {
            return;
        }

        for (int j = i ; j < candidates.size(); j++) {
            if (sum + candidates[j] > target) continue;
            sum += candidates[j];
            temp.push_back(candidates[j]);
            solve(j, candidates, target);
            sum -= candidates[j];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return result;
    }
};
