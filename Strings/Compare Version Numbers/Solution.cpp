// Problem link : https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2025-09-23
class Solution {
public:
    vector<string> give(string s) {
        stringstream ss(s);
        string take = "";
        vector<string> ans;
        while (getline(ss, take, '.')) {
            ans.push_back(take);
        }
        return ans;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<string> s1 = give(version1);
        vector<string> s2 = give(version2);

        int i = 0, m = s1.size(), n = s2.size();
        while (i < m || i < n) {
            int a = i < m ? stoi(s1[i]) : 0;
            int b = i < n ? stoi(s2[i]) : 0;
            if (a > b)
                return 1;
            else if (b > a)
                return -1;
            i++;
        }
        return 0;
    }
};
