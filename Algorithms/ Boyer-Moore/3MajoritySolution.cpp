// Problem Link : https://leetcode.com/problems/majority-element-ii/



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int maj1 = NULL;
        int maj2 = NULL;
        int n = nums.size();
        vector<int> ans;
        for (auto& it : nums) {
            if (it == maj1) {
                count1++;
            } else if (it == maj2) {
                count2++;
            } else if (count1 == 0) {
                maj1 = it;
                count1 = 1;
            } else if (count2 == 0) {
                maj2 = it;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        int freq1 = 0;
        int freq2 = 0;
        for (auto& it : nums) {
            if (it == maj1)
                freq1++;
            else if (it == maj2)
                freq2++;
        }

        if (freq1 > n / 3)
            ans.push_back(maj1);
        if (freq2 > n / 3)
            ans.push_back(maj2);
        return ans;
    }
};
