// Problem Link : https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/description/?envType=daily-question&envId=2026-06-02

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landDuration.size();
        int m = waterDuration.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int landEnd = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                int waterStart = max(waterStartTime[j], landEnd);
                ans = min(ans, waterStart + waterDuration[j]);
            }
        }

        for (int j = 0; j < m; j++) {
            int waterEnd = waterStartTime[j] + waterDuration[j];
            for (int i = 0; i < n; i++) {
                int landStart = max(waterEnd, landStartTime[i]);
                ans = min(ans, landStart + landDuration[i]);
            }
        }

        return ans;
    }
};
