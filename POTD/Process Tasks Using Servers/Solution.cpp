// Problem Link : https://leetcode.com/problems/process-tasks-using-servers/description/?envType=daily-question&envId=2026-11-07
using ll = long long;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        vector<int> ans(m);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            active;

        for (int i = 0; i < n; ++i)
            active.push({servers[i], i});

        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>,
                       greater<>>
            busy;

        ll time = 0;
        for (int i = 0; i < m; ++i) {

            time = max(time, (ll)i);

            if (active.empty()) {
                time = max(time, get<0>(busy.top()));
            }


            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [f, w, i] = busy.top();
                busy.pop();
                active.push({w, i});
            }


            auto [weight, index] = active.top();
            active.pop();

            ans[i] = index;
            busy.push({time + tasks[i], weight, index});
        }

        return ans;
    }
};
