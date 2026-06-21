// Problem Link : https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/description/
class Solution {
public:
    int maxDistance(string moves) {

        int u = 0, d = 0, r = 0, l = 0;
        int t = 0;
        for (auto& it : moves) {
            if (it == 'U')
                u++;
            else if (it == 'D')
                d++;
            else if (it == 'L')
                l++;
            else if (it == 'R')

                r++;
            else
                t++;
        }

        int ans =  abs(u - d) + abs(r - l) + t;
        return ans;
    }
};
