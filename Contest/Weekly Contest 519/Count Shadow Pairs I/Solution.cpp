// Problem Link :  Count Shadow Pairs I
using ll = long long;
class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack<pair<int, int>> st;
        st.push({nums[0], 1});
        ll s = 1;
        ll ans = 0;

        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int current = nums[i];

            while (!st.empty() && st.top().first > current) {
                s -= st.top().second;
                st.pop();
            }

            if (st.empty()) {
                st.push({current, 1});
            } else {
                if (st.top().first == current) {
                    ans += (s - st.top().second);
                    st.top().second += 1;

                } else {
                    ans += s;
                    st.push({current, 1});
                }
            }

            s++;
        }

        return ans;
    }
};
