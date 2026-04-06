// Problem Link : https://leetcode.com/problems/mirror-frequency-distance/description/ 

class Solution {
public:
    int mirrorFrequency(string s) {
        map<char, int> mp;
        for (auto& it : s) {
            mp[it]++;
        }
        int ans = 0;

        for (int i = 0; i < 13; i++) {

            ans += abs(mp['a' + i] - mp['z' - i]);

            if (i >= 5)
                continue;
            ans += abs(mp['0' + i] - mp['9' - i]);
        }

        return ans;
    }
};
