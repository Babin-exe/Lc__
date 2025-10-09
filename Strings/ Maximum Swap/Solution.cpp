// Problem Link :  https://leetcode.com/problems/maximum-swap/
class Solution {
public:
    int maximumSwap(int num) {
        string hehe = to_string(num);
        int n = hehe.size();
        vector<int> index(n);
        index[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            int id = index[i + 1];
            if (hehe[i] > hehe[id])
                index[i] = i;
            else
                index[i] = id;
        }

        for (int i = 0; i < n; i++) {
            if (hehe[i] < hehe[index[i]]) {
                swap(hehe[i], hehe[index[i]]);
                string s(begin(hehe), end(hehe));
                return stoi(s);
            }
        }
        return num;
    }
};
