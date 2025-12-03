// Problem Link : https://leetcode.com/problems/combination-sum-ii/

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
        if (i == candidates.size() || sum > target)
            return;

        for (int j = i; j < candidates.size(); j++) {

            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            sum += candidates[j];
            temp.push_back(candidates[j]);

            solve(j + 1, candidates, target);
            sum -= candidates[j];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        solve(0, candidates, target);
        return result;
    }
};
