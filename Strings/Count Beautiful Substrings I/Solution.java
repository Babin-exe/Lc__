// Problem link : https://leetcode.com/problems/count-beautiful-substrings-i/description/
class Solution {

    public boolean isVowel(Character ch) {
        return "aeiou".indexOf(ch) != -1;
    }

    public int beautifulSubstrings(String s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            int v_count = 0, c_count = 0;
            if (isVowel(ch)) {
                v_count++;
            } else {
                c_count++;
            }

            for (int j = i + 1; j < n; j++) {
                char c = s.charAt(j);
                if (isVowel(c))
                    v_count++;
                else
                    c_count++;

                if (v_count == c_count && (v_count * c_count) % k == 0)
                    ans++;

            }

        }
        return ans;
    }
}
