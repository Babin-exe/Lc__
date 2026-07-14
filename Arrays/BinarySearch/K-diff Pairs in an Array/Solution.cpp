// Problem Link : https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = n - 1;
            int target = nums[i] + k;

            while (l <= r) {

                int mid = l + (r - l) / 2;

                int val = nums[mid];

                if (val == target) {
                    ans++;
                    break;
                } else if (target > val) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return ans;
    }
};
