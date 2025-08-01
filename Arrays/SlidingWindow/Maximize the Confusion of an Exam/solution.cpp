// Problem link : https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
class Solution {

private:
    int blackBox(string s, int k, char c) {
        int ans = 0, i = 0, j = 0, flips = 0;

        while (j < s.length()) {

            if (s[j] != c)
                flips++;

            while (flips > k) {

                if (s[i] != c)
                    flips--;

                i++;
            }

            ans = max(ans, (j - i + 1));
            j++;
        }

        return ans;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        return max(blackBox(answerKey, k, 'T'), blackBox(answerKey, k, 'F'));
    }
};
