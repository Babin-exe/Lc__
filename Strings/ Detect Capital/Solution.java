// Problem link : https://leetcode.com/problems/detect-capital/
class Solution {
    public boolean checkStuff(String check, char s, char e) {
        for (char ch : check.toCharArray()) {
            if (ch < s || ch > e)
                return false;
        }
        return true;
    }

    public boolean detectCapitalUse(String word) {
        if (checkStuff(word, 'A', 'Z') || checkStuff(word, 'a', 'z') || checkStuff(word.substring(1), 'a', 'z'))
            return true;
        return false;
    }
}
