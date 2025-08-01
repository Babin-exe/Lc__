// Problem link : https://leetcode.com/problems/subarrays-with-k-different-integers/
// Time complexity : O(n);
// Space Complexity : O(n)

class Solution {

private:
    int slidingWindow(vector<int>& nums, int k) {

        unordered_map<int, int> map;

        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;

        while (j < n) {

            map[nums[j]]++;

            while (map.size() > k) {

                map[nums[i]]--;
                if (map[nums[i]] == 0)
                    map.erase(nums[i]);
                i++;
            }
            j++;
            count = count + 1 + (j - i + 1);
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};


