// Problem Link : https://leetcode.com/problems/sliding-window-maximum/description/

// Priority Queue approach , O(nlogn)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});

            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            if (i >= k - 1) {
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         deque<int> dq;
//         for (int i = 0; i < n; i++) {
            
//             while (!dq.empty() && dq.front() <= i - k) {
//                 dq.pop_front();
//             }

//             while (!dq.empty() && nums[dq.back()] < nums[i]) {
//                 dq.pop_back();
//             }

//             dq.push_back(i);

//             if (i >= k - 1) {
//                 ans.push_back(nums[dq.front()]);
//             }
//         }

//         return ans;
//     }
// };
