// Problem Link : https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three/description/

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> mod0, mod1, mod2;
        for (int take : nums) {
            if (take % 3 == 0)
                mod0.push_back(take);
            else if (take % 3 == 1)
                mod1.push_back(take);
            else
                mod2.push_back(take);
        }

        int ans = 0;
        auto c = [](int a, int b) { return a > b; };
        sort(begin(mod0), end(mod0), c);
        sort(begin(mod1), end(mod1), c);
        sort(begin(mod2), end(mod2), c);

        if (mod0.size() >= 3)
            ans = max(ans, mod0[0] + mod0[1] + mod0[2]);
        if (mod1.size() >= 3)
            ans = max(ans, mod1[0] + mod1[1] + mod1[2]);
        if (mod2.size() >= 3)
            ans = max(ans, mod2[0] + mod2[1] + mod2[2]);

        if (mod0.size() >= 1 && mod1.size() >= 1 && mod2.size() >= 1)
            ans = max(ans, mod0[0] + mod1[0] + mod2[0]);

        return ans;
    }
};
