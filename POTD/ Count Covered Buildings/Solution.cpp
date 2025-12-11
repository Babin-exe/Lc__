// Problem Link : https://leetcode.com/problems/count-covered-buildings/

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int count = 0;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        unordered_map<int, int> up;
        unordered_map<int, int> down;

        for (auto& take : buildings) {
            int x = take[0];
            int y = take[1];

            if (left.find(x) == left.end()) {
                left[x] = y;
            } else {
                left[x] = min(left[x], y);
            }
            if (right.find(x) == right.end()) {
                right[x] = y;
            } else {
                right[x] = max(right[x], y);
            }

            if (up.find(y) == up.end()) {
                up[y] = x;
            } else {
                up[y] = max(up[y], x);
            }
            if (down.find(y) == down.end()) {
                down[y] = x;
            } else {
                down[y] = min(down[y], x);
            }
        }

        for (auto& take : buildings) {
            int x = take[0];
            int y = take[1];

            bool l = left[x] < y;
            bool r = right[x] > y;
            bool u = up[y] > x;
            bool d = down[y] < x;

            if (l && r && u && d) {
                count++;
            }
        }
        return count;
    }
};
