// Problem link : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/



class Solution {
    public String answerString(String word, int numFriends) {
        int n = word.length();
        if (numFriends == 1) {
            return word;
        }
        int far = n - (numFriends - 1);
        int take;
        String hehe = "";
        String auh;

        for (int i = 0; i < n; i++) {
            take = Math.min(far, n - i);
            auh = word.substring(i, i + take);
            if (auh.compareTo(hehe) > 0) {
                hehe = auh;
            }

        }
        return hehe;
    }
}
