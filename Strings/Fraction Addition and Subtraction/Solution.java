// Problem Link : https://leetcode.com/problems/fraction-addition-and-subtraction/description/
class Solution {
    public int gcd(int a, int b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);

    }

    public String fractionAddition(String e) {

        int n = e.length();
        int i = 0;
        boolean isNegative = false;
        int nume = 0;
        int deno = 1;

        while (i < n) {
            int curr_nume = 0;
            int curr_deno = 0;

            isNegative = (e.charAt(i) == '-');

            if (e.charAt(i) == '+' || e.charAt(i) == '-')
                i++;

            while (i < n && Character.isDigit(e.charAt(i))) {
                int value = e.charAt(i) - '0';
                curr_nume = curr_nume * 10 + value;
                i++;

            }
            i++;

            while (i < n && Character.isDigit(e.charAt(i))) {
                int value = e.charAt(i) - '0';
                curr_deno = curr_deno * 10 + value;
                i++;
            }
            if (isNegative)
                curr_nume *= -1;

            nume = (nume * curr_deno) + (deno * curr_nume);
            deno = deno * curr_deno;

        }

        int value = Math.abs(gcd(nume, deno));
        nume /= value;
        deno /= value;
        return nume + "/" + deno;
    }
}
