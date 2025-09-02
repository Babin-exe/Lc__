// Problem link : https://leetcode.com/problems/orderly-queue/
class Solution {
    public String orderlyQueue(String s, int k) {
        if (k > 1) {
            char[] hehe = s.toCharArray();
            Arrays.sort(hehe);
            return new String(hehe);
        }

        String smallest = s;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            String rotated = s.substring(i) + s.substring(0, i);
            if (rotated.compareTo(smallest) < 0) {
                smallest = rotated;
            }
        }
        return smallest;
    }
}
