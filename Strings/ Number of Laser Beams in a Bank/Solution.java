// Problem link : https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0;
        int hehe = 0;
        for (String s : bank) {
        int count = 0;
            for (char ch : s.toCharArray()) {
                if (ch == '1')
                    count++;
            }
            if (count != 0) {

                ans += hehe * count;
                hehe = count;
            }
        }
        return ans;
    }
}
