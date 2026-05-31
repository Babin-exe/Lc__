// Problem Link : https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long ans = mass;
        sort(begin(asteroids), end(asteroids));
        for (auto& it : asteroids) {
            if (it > ans)
                return false;
            ans += it;
        }
        return true;
    }
};
