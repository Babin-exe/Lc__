// Problem LInk :  https://leetcode.com/problems/majority-element/description/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cd = nums[0];
        int count = 0;
        for (auto& it : nums) {
            if (cd == it) {
                count++;
            } else if (count > 0) {

                count--;
            } else {

                cd = it;
            }
        }
        int cc = 0;
        for (auto& it : nums) {
            if (it == cd)
                cc++;
        }

        if (cc > nums.size() / 2) {

            return cd;
        }
        return -1;
    }
};
