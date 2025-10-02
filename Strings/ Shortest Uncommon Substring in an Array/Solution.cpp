// Problem link : https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/description/

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (string& st : arr) {
            unordered_set<string> set;
            for (int i = 0; i < st.length(); i++) {
                for (int j = i + 1; j <= st.length(); j++) {
                    string sub = st.substr(i, j - i);
                    if (set.find(sub) == set.end()) {
                        mp[sub]++;
                        set.insert(sub);
                    }
                }
            }
        }

        for (string& st : arr) {
            string hehe = "";
            for (int i = 0; i < st.length(); i++) {
                for (int j = i + 1; j <= st.length(); j++) {
                    string sub = st.substr(i, j - i);
                    if (mp[sub] == 1 &&
                        (hehe == "" || sub.length() < hehe.length() ||
                         (sub.length() == hehe.length() && sub < hehe))

                    ) {
                        hehe = sub;
                    }
                }
            }
            ans.push_back(hehe);
        }
        return ans;
    }
};
