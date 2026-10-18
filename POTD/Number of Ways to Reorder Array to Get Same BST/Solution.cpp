// Problem Link : https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
/*
Observations :  
we have to fix the root first of all 

 root _ _ _ _ _ _ 
 

 now the other elements are either smaller or larger than the root

 so after knowing how many larger we have and how many smaller we have we can simply count the ways
 to place them by doing n-1 C either left or right size ,,,, and for left and right ,
 if there are enough elements internally they can also have some kind of combination so we recursively solve for them also ....


if we have a single element then it is the root itself 
so only one way and if we have two elements then the root is 
fixed so the other must stay , and above count from there we must solve ...

*/
using ll = long long;

class Solution {
public:
    vector<vector<ll>> p;
    const int MOD = 1e9 + 7;

    int solve(vector<int>& nums) {
        ll n = nums.size();
        if (n <= 2)
            return 1;

        ll root = nums[0];

        vector<int> left_tree;
        vector<int> right_tree;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < root)
                left_tree.push_back(nums[i]);
            else
                right_tree.push_back(nums[i]);
        }

        ll l = solve(left_tree) % MOD;
        ll r = solve(right_tree) % MOD;

        ll val = ((p[n - 1][left_tree.size()] * l) % MOD * r) % MOD;

        return val;
    }
    int numOfWays(vector<int>& nums) {
        ll n = nums.size();
        p.resize(n);

        for (int i = 0; i < n; ++i) {
            p[i].assign(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                p[i][j] = p[i - 1][j] % MOD + p[i - 1][j - 1] % MOD;
            }
        }

        return solve(nums) % MOD - 1;
    }
};
