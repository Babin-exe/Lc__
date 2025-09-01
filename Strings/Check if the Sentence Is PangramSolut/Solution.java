// Problem link : https://leetcode.com/problems/check-if-the-sentence-is-pangram/


class Solution {
    public boolean checkIfPangram(String sentence) {
        if (sentence.length() < 26)
            return false;
        char[] hehe = new char[26];
        int count = 0;

        for (int i = 0; i < sentence.length(); i++) {
            int idx = sentence.charAt(i) - 'a';
            if (hehe[idx] == 0) {
                hehe[idx]++;
                count++;
            }
        }
        if (count == 26)
            return true;
        return false;
    }
}
