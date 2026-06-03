// Problem Link : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/?envType=daily-question&envId=2026-06-03
class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int n = ld.size();
        int m = wd.size();

        int lmin = INT_MAX;
        int wmin = INT_MAX;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            lmin = min(lmin, (ls[i] + ld[i]));
        for (int j = 0; j < m; j++)
            wmin = min(wmin, (ws[j] + wd[j]));

        for (int j = 0; j < m; j++) {
            int start = max(lmin, ws[j]);
            ans = min(ans, (start + wd[j]));
        }

        for (int i = 0; i < n; i++) {
            int start = max(wmin, ls[i]);
            ans = min(ans, (start + ld[i]));
        }
        return ans;
    }
};
