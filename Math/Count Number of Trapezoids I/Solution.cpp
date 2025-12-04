// Problem Link : https://leetcode.com/problems/count-number-of-trapezoids-i/description/

class Solution {
public:
    unordered_map<int, int> mp;
    long long sum = 0;
    int MOD = 1e9 + 7;
    long long prev = 0;
    int solve(vector<vector<int>>& points) {
        for (auto& v : points) {
            mp[v[1]]++;
        }

        for (auto& v : mp) {
            int count = v.second;
            long long comb = (long long)count * (count - 1) / 2;
            sum += (comb * prev) % MOD;
            prev += comb;
        }
        return sum % MOD;
    }
    int countTrapezoids(vector<vector<int>>& points) { return solve(points); }
};
