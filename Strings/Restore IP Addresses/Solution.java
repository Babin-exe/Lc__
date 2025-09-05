// Problem link : https://leetcode.com/problems/restore-ip-addresses/
class Solution {
    List<String> result = new ArrayList<>();
    int n;

    public boolean noLeading(String taker) {
        if (taker.length() > 1 && taker.charAt(0) == '0')
            return false;
        int num = Integer.parseInt(taker);
        return num <= 255;
    }

    public void creator(String s, int index, int parts, String current) {
        if (index == n && parts == 4) {
            result.add(current.substring(0, current.length() - 1));
            return;

        }
        if (parts >= 4)
            return;

        if (index + 1 <= n) {
            creator(s, index + 1, parts + 1, current + s.substring(index, index + 1) + ".");
        }
        if (index + 2 <= n && noLeading(s.substring(index, index + 2))) {
            creator(s, index + 2, parts + 1, current + s.substring(index, index + 2) + ".");
        }
        if (index + 3 <= n && noLeading(s.substring(index, index + 3))) {
            creator(s, index + 3, parts + 1, current + s.substring(index, index + 3) + ".");
        }

    }

    public List<String> restoreIpAddresses(String s) {
        n = s.length();
        if (n < 4 || n > 12)
            return result;
        result.clear();
        String current = "";
        creator(s, 0, 0, current);
        return result;
    }
}
