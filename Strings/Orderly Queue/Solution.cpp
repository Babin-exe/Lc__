// Problem link: https://leetcode.com/problems/orderly-queue/

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(begin(s), end(s));
            return s;
        }
        string auh = s;
        for (int i = 1; i<=s.length()-1; i++) {
        string result =  s.substr(i) + s.substr(0, i);
            auh = min(result, auh);
        }
        return auh;
    }
};
