// Problem Link :  https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int one = -1, two = -1;
        int idx = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                one = i;
                if (two != -1)
                    idx = min(idx, abs(i - two));
            } else if (nums[i] == 2) {
                two = i;
                if (one != -1)
                    idx = min(idx, abs(i - one));
            }
        }

        return idx == INT_MAX ? -1 : idx;
    }
};
