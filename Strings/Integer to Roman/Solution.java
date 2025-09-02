// Problem link : https://leetcode.com/problems/integer-to-roman/


class Solution {
    static int[] numbers = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    static String[] romans = { "M", "CM", "D", "CD", "C",
            "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    public String intToRoman(int num) {

        StringBuilder ans = new StringBuilder("");
        for (int i = 0; i < 13; i++) {
            if (num == 0)
                break;
            int times = num / numbers[i];

            while (times-- > 0) {
                ans.append(romans[i]);
            }

            num = num % numbers[i];

        }
        return ans.toString();
    }
}
