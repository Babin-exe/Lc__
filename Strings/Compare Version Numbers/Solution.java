// Problem link : https://leetcode.com/problems/compare-version-numbers/?envType=daily-question&envId=2025-09-23
class Solution {
    public int compareVersion(String version1, String version2) {
        String s1[] = version1.split("\\.");
        String s2[] = version2.split("\\.");
        int i = 0, m = s1.length, n = s2.length;
        while (i < m || i < n) {
            int num1 = i < m ? Integer.parseInt(s1[i]) : 0;
            int num2 = i < n ? Integer.parseInt(s2[i]) : 0;
            if (num1 > num2) {
                return 1;
            } else if (num2 > num1) {
                return -1;
            }
            i++;
        }
        return 0;
    }
}
