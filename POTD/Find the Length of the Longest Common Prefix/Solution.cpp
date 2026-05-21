// Problem Link : https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/?envType=daily-question&envId=2026-05-21

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        int cnt = 0;
        int n = arr1.size();
        for (int i = 0; i < n; i++) {
            int t = arr1[i];

            while (t != 0) {
                st.insert(t);
                t /= 10;
            }
        }

        int m = arr2.size();
        for (int i = 0; i < m; i++) {

            int t = arr2[i];
            int l = to_string(t).size();
            while (t != 0) {

                if (st.contains(t)) {
                    cnt = max(cnt, l);
                    break;
                }
                t /= 10;
                l--;
            }
        }
        return cnt;
    }
};

