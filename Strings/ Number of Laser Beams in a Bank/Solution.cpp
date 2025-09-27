// Problem link : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        for (string& st : bank) {
            int count = 0;
            for (char& ch : st) {
                if (ch == '1')
                    count++;
            }
            if (count > 0) {
                ans += (count * prev);
                prev = count;
            }
        }
        return ans;
    }
};
