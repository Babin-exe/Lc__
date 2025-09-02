// Problem link : https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        int m = word1.size();
        int n = word2.size();
        int left_word = 0;
        int i = 0;
        int right_word = 0;
        int j = 0;

        while (left_word < m && right_word < n) {

            if (word1[left_word][i] != word2[right_word][j])
                return false;

            i++;
            j++;

            if (i == word1[left_word].size()) {
                left_word++;
                i = 0;
            }

            if (j == word2[right_word].size()) {
                right_word++;
                j = 0;
            }
        }
        return left_word == m && right_word == n;

    }
};
