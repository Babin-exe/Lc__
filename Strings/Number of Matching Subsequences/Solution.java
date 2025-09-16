// Problem link: https://leetcode.com/problems/number-of-matching-subsequences/
class Solution {

    public int binarySearch(List<Integer> ls, int prev) {
        int l = 0;
        int r = ls.size() - 1;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ls.get(mid) > prev) {
                ans = ls.get(mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    public boolean isValid(String t, HashMap<Character, ArrayList<Integer>> mp) {
        int prev = -1;
        for (int j = 0; j < t.length(); j++) {
            if (!mp.containsKey(t.charAt(j)))
                return false;

            List<Integer> hehe = mp.get(t.charAt(j));
            int idx = binarySearch(hehe, prev);
            if (idx == -1)
                return false;

            prev = idx;

        }
        return true;

    }

    public int numMatchingSubseq(String s, String[] words) {

        HashMap<Character, ArrayList<Integer>> mp = new HashMap<>();
        for (int j = 0; j < s.length(); j++) {
            mp.computeIfAbsent(s.charAt(j), k -> new ArrayList<Integer>()).add(j);
        }

        int ans = 0;
        for (int i = 0; i < words.length; i++) {
            if (isValid(words[i], mp))
                ans++;
        }
        return ans;
    }
}
