// Problem Link : https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
// Time complexity  : O(n * sqrt(nums[i]))
class Solution {
public:
    int solve(int nums) {
        int sum = 0;
        int count = 0;
        for (int i = 1; i * i <= nums; i++) {
            if (nums % i == 0) {
                count++;
                sum += i;
                if ((nums / i) != i) {
                    sum += (nums / i);
                    count++;
                }
            }
        }

        if (count == 4) {
            return sum;

        } else {

            return -1;
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int take = -1;
            take = solve(nums[i]);
            if (take != -1) {
                ans += take;
            }
        }
        return ans;
    }
};
