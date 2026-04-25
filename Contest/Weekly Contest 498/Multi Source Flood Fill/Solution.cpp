// Problem Link : https://leetcode.com/problems/multi-source-flood-fill/

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> hehe(n, vector<int>(m));

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        priority_queue<tuple<int, int, int>> pq;
        vector<tuple<int, int, int>> rc;

        for (auto& it : sources) {
            int r = it[0];
            int c = it[1];
            int val = it[2];

            hehe[r][c] = max(hehe[r][c], val);
            pq.push({val, r, c});
        }

        while (true) {
            while (!pq.empty()) {
                auto [val, r, c] = pq.top();
                pq.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = r + dx[i];
                    int ny = c + dy[i];

                    if ((nx >= 0 && nx < n) && (ny < m && ny >= 0)) {
                        if (hehe[nx][ny] == 0) {
                            hehe[nx][ny] = val;
                            rc.push_back({val, nx, ny});
                        }
                    }
                }
            }

            for (auto [val, r, c] : rc) {
                pq.push({val, r, c});
            }

            rc.clear();

            if (pq.empty())
                break;
        }
        return hehe;
    }
};
