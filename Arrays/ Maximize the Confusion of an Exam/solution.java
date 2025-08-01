// Problem link : https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

class Solution {

    private int slidingWindow(String s, int k, char ch) {

        int right = 0;
        int left = 0;
        int flips = 0;
        int count = 0;

        while (right < s.length()) {

            if (s.charAt(right) != ch)
                flips++;

            //lets shrink the winodw if we can
            while (flips > k) {
                if (s.charAt(left) != ch)
                    flips--;
                left++;
            }

            count = Math.max(count, (right - left + 1));
            right++;
        }

        return count;
    }

    public int maxConsecutiveAnswers(String answerKey, int k) {

        return Math.max(slidingWindow(answerKey, k, 'F'), slidingWindow(answerKey, k, 'T'));

    }
}
