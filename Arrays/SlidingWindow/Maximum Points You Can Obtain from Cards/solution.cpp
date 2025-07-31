// Problem link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// Time complexity : O(k);
// Space Complexity : O(1);


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi = 0;
        int sum = 0;
        int n = cardPoints.size();
        // lets first find the k sum of the array from l->k
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        maxi = sum;
    
        int idx = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[idx];
            idx--;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
