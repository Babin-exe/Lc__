// Problem Link : https://leetcode.com/problems/construct-uniform-parity-array-ii/


class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oc = 0, ec = 0;
        int le = INT_MAX, lo = INT_MAX;
        int n = nums1.size();
        if (n == 1)
            return true;
        for (int tk : nums1) {
            if ((tk & 1) == 1) {
                oc++;
                if (lo > tk)
                    lo = tk;
            } else {
                ec++;
                if (le > tk)
                    le = tk;
            }
        }

        if (oc == n || ec == n)
            return true;

        return lo < le;
    }
};
