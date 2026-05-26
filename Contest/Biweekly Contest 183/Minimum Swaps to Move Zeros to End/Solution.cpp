// Problem Link : https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end/
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int nz = 0;
        for (int t : nums) {
            if (t != 0)
                nz++;
        }

        int c = 0;
        for (int i = 0; i < nz; i++) {
            if (nums[i] == 0)
                c++;
        }
        return c;
    }
};
