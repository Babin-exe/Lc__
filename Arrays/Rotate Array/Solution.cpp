// Problem Link : https://leetcode.com/problems/rotate-array/description/
class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
            l++;
            r--;
        }
        cout << "Reversing lets googog";
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);

        cout << "Okayaay" << "\n";
    }
};
