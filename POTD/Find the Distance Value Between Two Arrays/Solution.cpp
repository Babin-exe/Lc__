// Problem Link : https://leetcode.com/problems/find-the-distance-value-between-two-arrays/?envType=daily-question&envId=2026-11-05
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int a = 0;
        for (auto it : arr1) {
            bool t = true;

            for (auto ti : arr2) {
                if (abs(it - ti) <= d) {
                    t = false;
                    break;
                }
            }
                  if(t)  a++;
        }
        return a;
    }
};
