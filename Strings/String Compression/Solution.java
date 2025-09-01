// Problem link : https://leetcode.com/problems/string-compression/description/

class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int index = 0;
        int i = 0;
        while (i < n) {

            char current_char = chars[i];
            int count = 0;

            while (i < n && chars[i] == current_char) {
                count++;
                i++;
            }

            chars[index] = current_char;
            index++;
            if (count > 1) {

                String ans = String.valueOf(count);

                for (char take : ans.toCharArray()) {
                    chars[index] = take;
                    index++;
                }

            }

        }

        return index;

    }
}
