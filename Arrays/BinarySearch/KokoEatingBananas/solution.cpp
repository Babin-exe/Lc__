// Problem link : https://leetcode.com/problems/koko-eating-bananas/

class Solution {

public:
    bool Hehe(vector<int>& piles, int mid, int h) {
        int sum = 0;
        for (int take : piles) {
            sum += (take + mid - 1) / mid;
        }
        return sum <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int i = 1, j = *max_element(begin(piles), end(piles));
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (Hehe(piles,mid,h)) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return i;
    }
};
