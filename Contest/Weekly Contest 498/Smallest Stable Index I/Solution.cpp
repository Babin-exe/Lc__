// Problem Link : https://leetcode.com/problems/smallest-stable-index-i/description/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> maxis(n);
        vector<int> minis(n);

        maxis[0] = nums[0];

        for (int i = 1; i < n; i++) {
            maxis[i] = max(maxis[i - 1], nums[i]);
        }

        minis[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            minis[i] = min(minis[i + 1], nums[i]);
        }

        int ans = 0;
        bool changed = false;

        for (int i = 0; i < n; i++) {
            int mx = maxis[i];
            int mi = minis[i];

            if ((mx - mi) <= k) {
                ans = i;
                changed = true;
                break;
            }
        }
        if (changed)
            return ans;
        return -1;
    }
};
