// Problem Link : https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/
class Solution {

public:
    bool checker(long long x, int vt) {
        int last = x % 10;
        int first = -1;
        while (x != 0) {
            first = x % 10;
            x /= 10;
        }

        return first == last && first == vt;
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (checker(sum, x))
                    ans++;
            }
        }
        return ans;
    }
};
