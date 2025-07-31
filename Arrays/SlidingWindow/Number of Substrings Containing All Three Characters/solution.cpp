// Problem link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int a_count = 0, b_count = 0, c_count = 0;
        int count = 0;

        while (j < n) {

            if (s[j] == 'a')
                a_count++;
            if (s[j] == 'b')
                b_count++;
            if (s[j] == 'c')
                c_count++;

            if (a_count > 0 && b_count > 0 && c_count > 0)
                count = count + 1 + (n - 1 - j);

            while (i < j && a_count > 0 && b_count > 0 && c_count > 0) {

                if (s[i] == 'a')
                    a_count--;
                if (s[i] == 'b')
                    b_count--;
                if (s[i] == 'c')
                    c_count--;

                if (a_count > 0 && b_count > 0 && c_count > 0)
                    count = count + 1 + (n - 1 - j);

                i++;
            }
            j++;
        }
        return count;
    }
};

