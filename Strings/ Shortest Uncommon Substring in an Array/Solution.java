// Problem link : https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/description/

class Solution {
    public String[] shortestSubstrings(String[] arr) {
        HashMap<String, Integer> hehe = new HashMap<>();
        List<String> answer = new ArrayList<>();

        for (String str : arr) {
            Set<String> st = new HashSet<>();
            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {
                    String s = str.substring(i, j);
                    if (!st.contains(s)) {
                        st.add(s);
                        hehe.put(s, hehe.getOrDefault(s, 0) + 1);

                    }
                }
            }
        }
        for (String str : arr) {
            String nsk = "";
            for (int i = 0; i < str.length(); i++) {
                for (int j = i + 1; j <= str.length(); j++) {
                    String sub = str.substring(i, j);

                    if (hehe.get(sub) == 1 && (nsk == ""
                            || sub.length() < nsk.length() ||
                            sub.length() == nsk.length() && nsk.compareTo(sub) > 0)) {
                        nsk = sub;
                    }

                }
            }
            answer.add(nsk);
        }
        return answer.toArray(new String[0]);
    }
}
