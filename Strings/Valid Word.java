// Problem link : https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15



class Solution {
    public boolean isValid(String word) {
        int n = word.length();
        if (n < 3) {
            return false;
        }
        int num = 0;
        int vow = 0;
        int cons = 0;
        int wrong = 0;

        for (int i = 0; i < n; i++) {

            char ch = word.charAt(i);
            if (Character.isLetter(ch)) {
                if (ch == 'a'
                        || ch == 'e'
                        || ch == 'i'
                        || ch == 'o'
                        || ch == 'u'
                        || ch == 'A'
                        || ch == 'E'
                        || ch == 'I'
                        || ch == 'O'
                        || ch == 'U') {
                    vow++;
                } else {
                    cons++;
                }
            } else if (Character.isDigit(ch)) {
                num++;
            } else {
                wrong++;
            }
        }
        if (((vow > 0 && cons > 0))
                && (vow + cons + num >= 3)
                && (wrong == 0)) {
            return true;
        }
        return false;
    }
}
