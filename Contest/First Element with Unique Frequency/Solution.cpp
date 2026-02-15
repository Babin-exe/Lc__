// Problem Link : https://leetcode.com/problems/first-element-with-unique-frequency/
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> sec;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto& it : mp) {
            int count = it.second;
            sec[count]++;
        }

        for (int num : nums) {
            if (sec[mp[num]] == 1)
                return num;
        }
        return -1;
    }
};
