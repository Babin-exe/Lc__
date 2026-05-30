// Problem Link : https://leetcode.com/problems/block-placement-queries/description/?envType=daily-question&envId=2026-05-30
/*
Brute force


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        vector<bool> r;

        set<int> st;
        for (auto& q : queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            } else {
                int x = q[1];
                int sz = q[2];

                int prev = 0;
                bool f = false;

                for (auto& curr : st) {

                    if (curr > x)
                        break;
                    if (curr - prev >= sz) {
                        f = true;
                        break;
                    }

                    prev = curr;
                }

                f = (x - prev) >= sz;

                r.push_back(f);
            }
        }
        return r;
    }
};
*/


Segment Tree : // will update later ....
