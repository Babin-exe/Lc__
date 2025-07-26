// Problem link : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/


// c++  Solution : 
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {

//         int i = 0, j = 0;
//         int n = nums.size();
//         bool auh = true;
//         int sum = 0;
//         int maxi = 0;
//         int zero = 0;

//         while (j < n) {
//             if (nums[j] == 0) {
//                 zero++;
//                 auh = false;
//                 while (i < j && zero > 1) {
//                     if (nums[i] == 0) {
//                         zero--;
//                     } else {
//                         sum--;
//                     }
//                     i++;
//                 }
//             }

//             else {
//                 sum++;
//                 maxi = max(maxi, sum);
//             }
//             j++;
//         }
//         return auh ? n - 1 : maxi;
//     }
// };




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Java solution : 




class Solution {
    public int longestSubarray(int[] nums) {

        int i = 0, j = 0;
        int n = nums.length;

        int ans = 0;
        int maxi = 0;
        int zero = 0;
        boolean all = true;

        while (j < n) {
            if (nums[j] == 0) {
                zero++;
                all = false;
                while (zero > 1 && i < j) {
                    if (nums[i] == 0) {
                        zero--;
                    } else {
                        ans--;
                    }
                    i++;
                }
            } else {
                ans++;
                maxi = Math.max(maxi, ans);
            }

            j++;
        }
        return all ? n - 1 : maxi;
    }
}
