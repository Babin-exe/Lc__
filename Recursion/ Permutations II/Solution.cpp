// Problem Link : https://leetcode.com/problems/permutations-ii/description/

class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> temp;
    vector<vector<int>> result;

    void solve(vector<int>& nums) {
        int n = nums.size();
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for (auto& [num, count] : mp) {
            if (count == 0)
                continue;
            temp.push_back(num);
            mp[num]--;
            solve(nums);
            temp.pop_back();
            mp[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        solve(nums);
        return result;
    }
};
