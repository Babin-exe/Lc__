// Problem Link : https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        int maxi = *max_element(begin(costs), end(costs));
        vector<int> m(maxi + 1, 0);
        for (auto& it : costs)
            m[it]++;

        for (int i = 1; i <= maxi; i++) {
            int fq = m[i];
            if (fq == 0)
                continue;

            int t = min(m[i], coins / i);
            coins -= (i * t);
            ans += t;
        }

        return ans;
    }
};
