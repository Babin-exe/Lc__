// Problem Link: https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // unordered_map<int,int> freq;
        // int d = 0;

        // for(int x : nums) {
        //     freq[x]++;
        //     if(freq[x] == 2) d++;
        // }

        // int ops = 0;
        // int idx = 0;
        // int n = nums.size();

        // while(d > 0 && idx < n) {

        //     ops++;
        //     int removeCnt = min(3, n - idx);

        //     while(removeCnt--) {
        //         int x = nums[idx++];
        //         int old = freq[x];

        //         freq[x]--;

        //         if(old == 2) d--;
        //     }
        // }

        // return ops;

        map<int, int> mp;
        int c = 0, n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            if (mp[nums[i]])
                break;
            mp[nums[i]]++;
            c++;
        }
        return (n - c + 2) / 3;
    }
};
