// Problem Link :https://leetcode.com/problems/minimum-moves-to-balance-circular-array/description/

class Solution {
public:
    typedef long long ll;
    long long minMoves(vector<int>& balance) {
        int neg = -1;
        ll sum = 0;
        int n = balance.size();
        for (int i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0)
                neg = i;
        }

        if (neg == -1)
            return 0;
        if (sum < 0)
            return -1;

        ll moves = 0;
        int dist = 1;
        while (balance[neg] < 0) {
            ll left = (neg - dist + n) % n;
            ll right = (neg + dist) % n;
            ll temp = balance[left] + balance[right];

            if (left == right) {
                temp -= balance[left];
            }

            ll need = -balance[neg];
            ll taken = min(need, temp);

            balance[neg] += taken;
            moves += (taken * dist);

            dist++;
        }

        return moves;
    }
};
