// Problem Link : https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14
class Solution {
public:
    bool isGood(vector<int>& nums) {
        map<int, int> mp;
        int maxi = 0;
        for (auto& it : nums) {
            maxi = max(maxi, it);
            mp[it]++;
        }

        for (int i = 1; i <= maxi - 1; i++) {
            if (mp[i] != 1)
                return false;
        }

        if (mp[maxi] != 2)
            return false;
        return true;
    }
};
