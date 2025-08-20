// Problem link :  https://leetcode.com/problems/number-of-flowers-in-full-bloom/
class Solution {

public:
    int flowerBloom(vector<int> &arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

public:
    int flowerDied(vector<int> &arr, int target) {
        int l = 0, r = arr.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& people) {

        vector<int> left(flowers.size());
        vector<int> right(flowers.size());
        int m = flowers.size();
        int n = people.size();
        vector<int> ans(n);
        for (int i = 0; i < m; i++) {
            left[i] = flowers[i][0];
            right[i] = flowers[i][1];
        }

        sort(begin(left), end(left));
        sort(begin(right), end(right));

        for (int i = 0; i < n; i++) {

            int mid = people[i];

            int start = flowerBloom(left, mid);
            int end = flowerDied(right, mid);
            ans[i] = (start - end);
        }

        return ans;
    }
};
