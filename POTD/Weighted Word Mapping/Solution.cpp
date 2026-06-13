// Problem Link : https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for (auto& st : words) {
            int sum = 0;
            for (auto& ch : st) {
                sum += weights[ch - 'a'];
            }
            sum %= 26;
            ans += ('z' - sum);
        }
        return ans;
    }
};
