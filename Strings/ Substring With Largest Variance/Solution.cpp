// Problem link : https://leetcode.com/problems/substring-with-largest-variance/
class Solution {
public:
    int largestVariance(string s) {
        vector<int> count(26, 0);
        for (char& ch : s) {
            count[ch - 'a']++;
        }
        if (s.length() == 2)
            return 0;

        int ans = 0;

        for (char first = 'a'; first <= 'z'; first++) {
            for (char second = 'a'; second <= 'z'; second++) {

                if (count[first - 'a'] == 0 || count[second - 'a'] == 0)
                    continue;

                int f1 = 0, f2 = 0;
                bool seenBefore = false;

                for (char& ch : s) {
                    if (ch == first)
                        f1++;
                    if (ch == second)
                        f2++;

                    if (f2 > 0) {
                        ans = max(ans, f1 - f2);
                    } else {
                        if (seenBefore == true) {
                            ans = max(ans, f1 - 1);
                        }
                    }

                    if (f2 > f1) {
                        f1 = 0;
                        f2 = 0;
                        seenBefore = true;
                    }
                }
            }
        }

        return ans;
    }
};
