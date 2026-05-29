// Problem Link : https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/?envType=daily-question&envId=2026-05-29

class Solution {
public:
    int find(int t) {
        int fin = 0;
        while (t != 0) {
            fin += (t % 10);
            t /= 10;
        }
        return fin;
    }
    int minElement(vector<int>& nums) {

        int ans = INT_MAX;
        for (int t : nums) {
            ans = min(ans, find(t));
        }
        return ans;
    }
};
