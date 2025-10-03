// Problem link : https://leetcode.com/problems/sort-the-jumbled-numbers/description/
class Solution {

public:
    string getMapped(string& hehe, vector<int>& mapping) {
        string mpNum = "";

        for (int i = 0; i < hehe.length(); i++) {
            char ch = hehe[i];
            int num = ch - '0';
            mpNum += to_string(mapping[num]);
        }
        return mpNum;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            string hehe = to_string(nums[i]);
            string mapped = getMapped(hehe, mapping);
            int num = stoi(mapped);
            mp.push_back({num, i});
        }
        sort(begin(mp), end(mp));

        vector<int> result;
        for (auto& a : mp) {
            int index = a.second;
            result.push_back(nums[index]);
        }
        return result;
    }
};
