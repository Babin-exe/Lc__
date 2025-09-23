// Problem link : https://leetcode.com/problems/find-unique-binary-string/description/
class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int n = nums.length;
        Set<String> st = new HashSet<>();
        for (int i = 0; i < (1 << n); i++) {
            String binary = Integer.toBinaryString(i);
            while (binary.length() < n)
                binary = "0" + binary;
            st.add(binary);
        }
        for (String s : nums) {
            st.remove(s);
        }
        return st.iterator().next();
    }
}
