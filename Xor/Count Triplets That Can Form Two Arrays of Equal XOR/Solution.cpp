// Problem Link : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> px(n, -1);
        px[0] = arr[0];
        for (int i = 1; i < n; i++) {
            px[i] = px[i - 1] ^ arr[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = px[j];
                if (i > 0) t ^= px[i - 1];
                if (t == 0) ans += (j - i);
            }
        }
        return ans;
    }
};
