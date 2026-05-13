// Problem Link : https://leetcode.com/problems/score-validator/description/

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> ans(2, 0);
        for (auto& it : events) {
            if (ans[1] == 10)
                return ans;

            if (it.length() == 1 && it >= "0" && it <= "6") {
                ans[0] += stoi(it);
            } else if (it == "W") {
                ans[1]++;
            } else {
                ans[0]++;
            }
        }
        return ans;
    }
};
