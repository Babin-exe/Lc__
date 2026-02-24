// Problem Link : https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ch_s1(26, 0);
        vector<int> ch_s2(26, 0);
        // Increase the frequency
        for (auto& it : s1) {
            ch_s1[it - 'a']++;
        }

        int n = s2.length();
        int k = s1.length();
        for (int j = 0; j < n; j++) {
            // Increase the frequency
            ch_s2[s2[j] - 'a']++;

            // Check if we are exceeding the window

            if (j >= k) {
                ch_s2[s2[j - k] - 'a']--;
            }

            // Check if vectors are equal after removal of extra stuff
            if (j >= k - 1 && ch_s1 == ch_s2)
                return true;
        }
        return false;
    }
};
