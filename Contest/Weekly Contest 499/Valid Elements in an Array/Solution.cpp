// Problem Link : https://leetcode.com/problems/valid-elements-in-an-array/description/
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], nums[i]);
        }

        right[n - 1] = (nums[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool leftt = (i == 0 || nums[i] > left[i - 1]);
            bool rightt = (i == n - 1 || nums[i] > right[i + 1]);

            if (leftt || rightt) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
