// Problem Link : https://leetcode.com/problems/sort-the-jumbled-numbers/
class Solution {
    public int[] sortJumbled(int[] mapping, int[] nums) {
        List<int[]> ans = new ArrayList<>();

        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < 10; i++) {
            mp.put(i, mapping[i]);
        }

        int n = nums.length;
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < n; i++) {

            String s = "" + nums[i];

            for (char ch : s.toCharArray()) {
                int num = ch - '0';
                char take = (char) (mp.get(num) + '0');
                sb.append(take);
            }
            ans.add(new int[] { Integer.parseInt(sb.toString()), i });
            sb.setLength(0);

        }
        ans.sort((a, b) -> Integer.compare(a[0], b[0]));

        int[] hehe = new int[n];
        for (int i = 0; i < ans.size(); i++) {
            int index = ans.get(i)[1];
            hehe[i] = nums[index];

        }

        return hehe;

    }
}
