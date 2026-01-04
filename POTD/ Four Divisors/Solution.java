// Problem Link : https://leetcode.com/problems/four-divisors/?envType=daily-question&envId=2026-01-04
class Solution {
    public int solve(int num) {
        int count = 0;
        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (count > 4)
                break;
            if (num % i == 0) {
                count++;
                sum += i;
                if (num / i != i) {
                    sum += (num / i);
                    count++;
                }
            }
        }
        if (count == 4)
            return sum;
        return 0;
    }

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            ans += solve(nums[i]);
        }
        return ans;
    }
}
