// Problem Link : https://leetcode.com/problems/minimum-cost-to-acquire-required-items/description/
using ll = long long;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        ll one = 1LL * max(need1, need2) * costBoth;

        ll two = 1LL * cost1 * need1 + 1LL * cost2 * need2;

        int mini = min(need1, need2);
        int maxi = max(need1, need2);

        int own_cost = need1 >  need2 ? cost1 : cost2;

        ll three = 1LL * mini * costBoth + 1LL * (maxi - mini) * own_cost;

        return min({one, two, three});
    }
};
