// Problem link : https://leetcode.com/problems/find-the-closest-palindrome/

class Solution {

    public void makePalindrome(long s, List<Long> ans, boolean isOdd) {
        long make = s;

        if (isOdd) {
            s /= 10;
        }
        long hehe = make;

        while (s > 0) {
            long val = s % 10;
            hehe = (hehe * 10) + val;
            s /= 10;
        }
        ans.add(hehe);

    }

    public String nearestPalindromic(String n) {
        int l = n.length();
        List<Long> ans = new ArrayList<>();
        int mid = (l % 2 == 0) ? l / 2 : (l / 2) + 1;
        long val = Long.parseLong(n.substring(0, mid));
        makePalindrome(val, ans, l % 2 != 0);
        makePalindrome(val - 1, ans, l % 2 != 0);
        makePalindrome(val + 1, ans, l % 2 != 0);

        ans.add((long) Math.pow(10, l - 1) - 1);
        ans.add((long) Math.pow(10, l) + 1);

        long original = Long.parseLong(n);
        long min_value = Long.MAX_VALUE;
        long auh = -1;

        for (int i = 0; i < ans.size(); i++) {

            long take = ans.get(i);
            if (take == original)
                continue;
            long diff = Math.abs(original - take);

            if (diff < min_value || (diff == min_value && take < auh)) {
                min_value = diff;
                auh = take;
            }

        }
        return "" + auh;
    }
}

