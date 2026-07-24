// Problem Link : https://leetcode.com/problems/single-number-ii/description/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int t = (1 << i);
            int one = 0;
            for (auto& it : nums) {
                if ((t & it) != 0)
                    one++;
            }
            if (one % 3 == 1) {
                ans = ans | t;
            }
        }

        return ans;
    }
};
