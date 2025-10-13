// Problem Link : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/

class Solution {
    public int maximumLength(String s) {
        HashMap<String, Integer> mp = new HashMap<>();
        int n = s.length();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = i; j < n; j++) {
                char ch = s.charAt(j);
                if (sb.length() == 0 || sb.charAt(sb.length() - 1) == ch) {
                    sb.append(ch);
                    String key = sb.toString();
                    mp.put(key, mp.getOrDefault(key, 0) + 1);
                } else {
                    break;
                }
            }
        }

        for (Map.Entry<String, Integer> val : mp.entrySet()) {
            if (val.getKey().length() > ans && val.getValue() >= 3) {
                ans = val.getKey().length();
            }
        }
        return ans;
    }
}


