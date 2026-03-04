// Problem Link : https://leetcode.com/problems/contiguous-array/description/

/*

Thought process:


We are saying if we got 1 it will increase the sum and if we get 0 it will
decrease the sum if that is so for an array to have equal 1's and 0's it is
exactly the same as finding subarray with sum k where k = 0.


okay so we know that if x is the sum in index i , and k is the subarray than x-k
is the other part .



if we have seen something specifically sum +/- 1 earlier what does that tell us
it tells us that something i have seen earlier is repeating again it means only
adding 0 to it would have resulted in gaining that so if i did the index i am at
- where have i seen that earlier i will get the array length that was 0


 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n  = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                sum--;
            else
                sum++;

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxi;
    }
};
