// Problem Link : https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(begin(folder), end(folder));
        vector<string> ans;
        ans.push_back(folder[0]);
        for (int i = 1; i < folder.size(); i++) {
            string curr = ans.back() + "/";
            if (folder[i].find(curr) != 0) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
