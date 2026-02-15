// Problem Link : https://leetcode.com/problems/toggle-light-bulbs/description/
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {

        unordered_map<int,int> count;

        for (int a : bulbs) {
            count[a]++;
        }

        vector<int> ans;
        for (auto &it : count) {
            int key = it.first;
            int value = it.second;

            if (value % 2 != 0)
                ans.push_back(key);
        }

        sort(begin(ans), end(ans));
        return ans;
    }
};
