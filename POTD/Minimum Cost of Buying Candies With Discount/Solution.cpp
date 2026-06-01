// Problem Link : https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/description/?envType=daily-question&envId=2026-06-01

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int ans = 0;
        int count = 0;
        int n = cost.size();
        for (int i = n - 1; i >= 0; i--) {
            if (count >= 2) {
                count = 0;
                continue;
            }
            ans += cost[i];
            count++;
        }

        return ans;
    }
};
