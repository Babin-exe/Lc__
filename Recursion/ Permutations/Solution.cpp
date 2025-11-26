// Problem Link : https://leetcode.com/problems/permutations/description/
class Solution {
public:
    set<int> st;
    vector<vector<int>> result;
    vector<int> temp;

    void solve(vector<int>& nums, vector<int>& temp) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(nums, temp);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, temp);
        return result;
    }
};

