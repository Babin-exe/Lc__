Problem link : https://leetcode.com/problems/longest-repeating-character-replacement/description/?source=submission-ac



C++ solution : class Solution {
public:
    int characterReplacement(string s, int k) {

        int i = 0;
        int n = s.size();
        int maxi = INT_MIN;
        int freq = 0;
        vector<int> arr(26);
        for (int j = 0; j < n; j++) {
            arr[s[j] - 'A']++;
            freq = max(freq, arr[s[j] - 'A']);

            while ((j - i + 1) - freq > k) {
                arr[s[i] - 'A']--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};
