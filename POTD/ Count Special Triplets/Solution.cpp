// Problem Link : https://leetcode.com/problems/count-special-triplets/

class Solution {
public:
    int mod = 1e9 + 7;
    int count = 0;
    int specialTriplets(vector<int>& nums) {
        std::unordered_map<int, int> left;
        std::unordered_map<int, int> right;
        int n = nums.size();

        for (int take : nums) {
            right[take]++;
        }

        for (int i = 0; i < n; i++) {
            right[nums[i]]--;

            if (left[nums[i] * 2] >= 1 && right[nums[i] * 2] >= 1) {
                long long le = left[nums[i] * 2] % mod;
                long long re = right[nums[i] * 2] % mod;

                long long prod = (le * re) % mod;
                count = (count + prod) % mod;
            }
            left[nums[i]]++;
        }

        return (int)count;
    }
};
