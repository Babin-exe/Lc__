// Problem Link : https://leetcode.com/problems/continuous-subarray-sum/description/
/* 
Thought process:

we will keep on taking the running sum , (first value of nums as is , 2nd value of the nums + first value of the same array , ..) so on ans so forth

if we can some do sum % k and the moudlo repeats it means we have added exactly k somewhere so that we have a repeated (sum%k)

if that is so , if we store the first occurance of the (sum%k)'s index  "i" ie the index and then the next time we see some sum with the same mod
just need to check the difference between the current index and what was stored earlier and if it is >=2 that is cool

  */
using ll = long long;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum % k) != mp.end()) {
                if (i - mp[sum % k] >= 2)
                    return true;
            } else {
                mp[sum % k] = i;
            }
        }
        return false;
    }
};
