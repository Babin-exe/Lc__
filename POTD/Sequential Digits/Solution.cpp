// Problem Link : https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";

        vector<int> ans;

        for (int i = 2; i <= 9; i++) {
            for (int j = 0; j + i <= 9; j++) {

                string sub = num.substr(j, i);
                int take = stoi(sub);

                if (take >= low && take <= high)
                    ans.push_back(take);
            }
        }

        sort(begin(ans), end(ans));

        return ans;
    }
};
