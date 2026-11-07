// Problem Link : https://leetcode.com/problems/count-magical-substring-pairs-i/
using ll = long long;
class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        int ans = 0;

        for (int j = 0; j < n - 1; ++j) {

            unordered_map<ll, ll> right;
            unordered_map<ll, ll> left;

            unordered_map<char, ll> left_count;
            unordered_map<char, ll> right_count;

            for (int l = j; l >= 0; --l) {
                left_count[s[l]]++;
                int ls = left_count.size();
                left[ls]++;
            }

            for (int r = j + 1; r <= n - 1; ++r) {
                right_count[s[r]]++;
                int rs = right_count.size();
                right[rs]++;
            }

            for (int i = 1; i <= 26; ++i) {
                ans += (right[i] * left[i]);
            }
        }
        return ans;
    }
};
