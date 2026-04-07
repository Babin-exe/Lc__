// Problem Link : https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/description/
using ll = long long;
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int lim = cbrt(n);
        unordered_map<long long, int> mp;
        vector<int> ans;
        for (int a = 1; a <= lim; a++) {
            ll asum = 1LL * a * a * a;
            for (int b = a; b <= lim; b++) {
                ll bsum = 1LL * b * b * b;
                ll tsum = asum + bsum;
                if (tsum > n)
                    break;
                mp[tsum]++;
            }
        }
        for (auto& it : mp) {
            if (it.second >= 2)
                ans.push_back(it.first);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
