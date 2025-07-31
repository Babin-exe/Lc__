// Problem link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Time complexity : O(n) ;
// Space complexity : O(1);
  
  class Solution {
    public int numberOfSubstrings(String s) {
        int a_count = 0, b_count = 0, c_count = 0;
        int n = s.length();
        int i = 0, j = 0;
        int count = 0;
        while (j < n) {

            if (s.charAt(j) == 'a') {
                a_count++;

            }

            else if (s.charAt(j) == 'b') {
                b_count++;
            }

            else if (s.charAt(j) == 'c') {
                c_count++;
            }

            if (a_count > 0 && b_count > 0 && c_count > 0) {
                count = count + 1 + (n - 1 - j);
            }

            while (i < j && a_count > 0 && b_count > 0 && c_count > 0) {

                if (s.charAt(i) == 'a') {
                    a_count--;
                } else if (s.charAt(i) == 'b') {
                    b_count--;
                } else if (s.charAt(i) == 'c') {
                    c_count--;
                }

                if (a_count > 0 && b_count > 0 && c_count > 0) {
                    count = count + 1 + (n - 1 - j);
                }
                i++;

            }

            j++;

        }
        return count;
    }
}
