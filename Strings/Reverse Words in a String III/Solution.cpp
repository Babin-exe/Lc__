// Problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        //     int n = s.length();
        //     int j = 0;
        //     for (int i = 0; i < n; i++) {
        //         if (s[i] != ' ') {
        //             j = i;
        //             while (j < n && s[j] != ' ') {
        //                 j++;
        //             }
        //             reverse(begin(s) + i, begin(s) + j);
        //             i = j;
        //         }
        //     }
        //     return s;

        string result = "";
        string token = "";
        stringstream auh(s);
        while (auh >> token) {
            reverse(begin(token), end(token));
            result += token + " ";
        }
        return result.substr(0, result.length() - 1);
    }
};
