// Problem Link : https://leetcode.com/problems/minimum-generations-to-target-point/description/

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        int n = points.size();

        map<vector<int>, int> mp;
        for (auto& it : points) {
            mp[it]++;
        }

        if (mp.find(target) != mp.end())
            return 0;

        int count = 0;

        while (true) {
            count++;
            bool Possible = false;
            int a = 0, b = 0, c = 0;
            int s = points.size();
            for (int i = 0; i < s; i++) {
                for (int j = i + 1; j < s; j++) {
                    a = (points[i][0] + points[j][0]) / 2;
                    b = (points[i][1] + points[j][1]) / 2;
                    c = (points[i][2] + points[j][2]) / 2;
                    if (mp.find({a, b, c}) == mp.end()) {
                        points.push_back({a, b, c});
                        mp[{a, b, c}]++;
                        Possible = true;
                    }
                    if (mp.find(target) != mp.end())
                        return count;
                }
            }

            if (!Possible)
                break;
        }

        return -1;
    }
};
