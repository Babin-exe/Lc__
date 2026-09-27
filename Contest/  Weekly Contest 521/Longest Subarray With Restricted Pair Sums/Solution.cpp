// Problem Link : https://leetcode.com/problems/longest-subarray-with-restricted-pair-sums/description/
class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        map<int, int> mp;

        while (j < n) {

            int x = nums[j];

            while (i < j) {

                bool bad = false;

                for (auto [v, f] : mp) {
                    int a = x - v;
                    int b = x + v;

                    auto it = mp.find(a);
                    if (it != mp.end()) {
                        if (a != v || f >= 2) {
                            bad = true;
                            break;
                        }
                    }

                    auto itt = mp.find(b);
                    if (itt != mp.end()) {
                        if (b != v || f >= 2) {
                            bad = true;
                            break;
                        }
                    }
                }
                if (!bad)
                    break;

                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            mp[x]++;
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
