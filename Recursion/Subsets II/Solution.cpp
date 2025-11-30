// Problem Link : https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;
    void solve(int i, vector<int>& nums) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i + 1, nums);
        temp.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        solve(i + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(begin(nums), end(nums));
        solve(0, nums);
        return result;
    }
};
