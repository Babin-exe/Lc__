// Problem link : https://leetcode.com/problems/longest-palindromic-substring/
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         int maxlen = 0;
//         int a;
//         // For odd length center
//         for (int i = 0; i < n; i++) {
//             int k = 0;
//             while (i - k >= 0 && i + k < n && s[i + k] == s[i - k]) {
//                 k++;
//             }
//             k--;
//             if ((i + k) - (i - k) + 1 > maxlen) {
//                 a = i - k;
//                 maxlen = (i + k) - (i - k) + 1;
//             }
//         }

//         // For even length
//         for (double i = 0.5; i < n; i++) {
//             double k = 0.5;
//             while (i - k >= 0 && i + k < n && s[i + k] == s[i - k]) {
//                 k++;
//             }
//             k--;
//             if ((i + k) - (i - k) + 1 > maxlen) {
//                 a = i - k;
//                 maxlen = (i + k) - (i - k) + 1;
//             }
//         }
//         return s.substr(a, maxlen);
//     }
// };

// Manacher's algorithm:
Solution in O(n) time :

class Solution {

public:
    string transform(string s) {
        string ch = "#";
        for (char& c : s) {
            ch += c;
            ch += '#';
        }
        return ch;
    }

public:
    string longestPalindrome(string s) {
        string t = transform(s);
        int n = t.size();
        vector<int> p(n);
        p[0] = 0;
        int maxLen = 0;
        int l = 0, r = 0;
        int center = 0;
        for (int i = 1; i < n; i++) {
            int k;
            if (i > r) {
                k = 0;
            } else {
                int j = l + (r - i);
                if (j - p[j] > l) {
                    p[i] = p[j];
                    continue;
                } else {
                    k = r - i;
                }
            }

            while (i + k < n && i - k >= 0 && t[i - k] == t[i + k]) {
                k++;
            }
            k--;
            p[i] = k;
            if (p[i] > maxLen) {
                maxLen = p[i];
                center = i / 2;
            }

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        return s.substr(center - (maxLen / 2), maxLen);
    }
};
