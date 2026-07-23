// Problem Link : https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();

        vector<bool> pos(3001, false);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pos[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> ans(3001, false);
        for (int i = 0; i <= 3000; i++) {
            for (int j = 0; j < n; j++) {
                if ((i ^ nums[j]) <= 3000 && pos[i ^ nums[j]]) {
                    ans[i] = true;
                }
            }
        }

        return count(begin(ans), end(ans), true);
    }
};
