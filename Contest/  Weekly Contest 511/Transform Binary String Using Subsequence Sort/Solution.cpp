// Problem Link : https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/
class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int oc = 0;
        int n = s.length();
        vector<int> sc(n);

        for (auto i = 0; i < n; ++i) {
            if (s[i] == '1')
                oc++;
            sc[i] = oc;
        }

        vector<bool> ans(strs.size(), true);
        for (auto i = 0; i < strs.size(); ++i) {
            string st = strs[i];
            int one_count = 0;
            int que_count = 0;

            for (char ch : st) {
                if (ch == '1')
                    one_count++;
                else if (ch == '?')
                    que_count++;
            }

            if (one_count > oc || one_count + que_count < oc) {
                ans[i] = false;
                continue;
            }

            int need = oc - one_count;
            for (auto j = n - 1; j >= 0 && need; j--) {
                if (st[j] == '?') {
                    st[j] = '1';
                    need--;
                }
            }

            for (auto j = 0; j < n; j++) {
                if (st[j] == '?')
                    st[j] = '0';
            }

            bool p = true;
            int c_one = 0;
            for (auto k = 0; k < n; k++) {
                if (st[k] == '1') {
                    c_one++;
                }

                if (c_one > sc[k]) {
                    p = false;
                    break;
                }
            }
            ans[i] = p;
        }

        return ans;
    }
};
