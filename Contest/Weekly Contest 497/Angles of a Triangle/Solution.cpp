// Problem Link : https://leetcode.com/problems/angles-of-a-triangle/


class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        const double PI = 3.141592653589793;
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if (a + b <= c || a + c <= b || b + c <= a)
            return {};

        vector<double> ans;

        double A = acos((b * b + c * c - a * a) / (2.0 * b * c));
        double B = acos((a * a + c * c - b * b) / (2.0 * a * c));
        double C = acos((a * a + b * b - c * c) / (2.0 * a * b));

        ans.push_back(A * (180.0 / PI));
        ans.push_back(B * (180.0 / PI));
        ans.push_back(C * (180.0 / PI));

        sort(begin(ans), end(ans));

        return ans;
    }
};
