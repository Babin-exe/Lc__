// Problem link : https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {

        if (n == 1)
            return "1";
        string hehe = countAndSay(n - 1);

        string ans = "";

        int a = hehe.length();
        for (int i = 0; i < hehe.length(); i++) {

            int count = 1;
            char ch = hehe[i];
            while (i < hehe.length() - 1 && hehe[i] == hehe[i + 1]) {
                count++;
                i++;
            }
            ans += to_string(count) + string(1, ch);
        }

        return ans;
    }
};
