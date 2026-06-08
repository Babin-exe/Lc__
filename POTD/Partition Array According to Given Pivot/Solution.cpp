// Problem Link : https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2026-06-08
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int pc = 0;
        vector<int> ans;
        vector<int>less,more;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int nn = nums[i];
            if (nn < pivot) {
                less.push_back(nn);
            } else if (nn > pivot) {
                more.push_back(nn);
            } else
                pc++;
        }

        for (auto& it : less)
            ans.push_back(it);
        while (pc--)
            ans.push_back(pivot);
        for (auto& it : more)
            ans.push_back(it);

        return ans;
    }
};
