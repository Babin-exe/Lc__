// Problem Link :  https://leetcode.com/problems/maximum-number-of-balloons/description/?envType=daily-question&envId=2026-06-22

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = 0;
        vector<int> ch(26, 0);
        for (auto& it : text) {
            ch[it - 'a']++;
        }

        return min({ch['b' - 'a'], ch['a' - 'a'], ch['l' - 'a'] / 2,
                    ch['o' - 'a'] / 2, ch['n' - 'a']});
    }
};
