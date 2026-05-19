// Problem Link : https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2026-05-19
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size() - 1;
        int n2 = nums2.size() - 1;
        int mini = INT_MAX;
        while (n1 >= 0 && n2 >= 0) {
            if (nums1[n1] > nums2[n2]) {

                n1--;
            } else if (nums1[n1] < nums2[n2]) {

                n2--;
            } else {
                mini = nums1[n1];
                n1--;
                n2--;
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
