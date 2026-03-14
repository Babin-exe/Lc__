// Problem Link : https://leetcode.com/problems/first-unique-even-element/description/

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& it : nums)
            mp[it]++;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] % 2 != 0)
                continue;

            auto it = mp[nums[i]];

            if (it == 1)
                return nums[i];
        }
        return -1;
    }
};
