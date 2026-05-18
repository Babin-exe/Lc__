// Problem Link : https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18
class Solution {

public:
    int minJumps(vector<int>& arr) {

        int n = arr.size() - 1;

        queue<int> q;
        int c = 0;
        q.push(0);
        vector<bool> v(n + 1, false);
        v[0] = true;

        map<int, vector<int>> mp;
        for (int i = 0; i < n + 1; i++) {
            mp[arr[i]].push_back(i);
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop();

                if (i == n)
                    return c;

                if (i - 1 >= 0 && !v[i - 1]) {
                    q.push(i - 1);
                    v[i - 1] = true;
                }

                if (i + 1 <= n && !v[i + 1]) {
                    q.push(i + 1);
                    v[i + 1] = true;
                }

                for (int idx : mp[arr[i]]) {
                    if (!v[idx]) {
                        q.push(idx);
                        v[idx] = true;
                    }
                }
                mp[arr[i]].clear();
            }
            c++;
        }
        return c;
    }
};
