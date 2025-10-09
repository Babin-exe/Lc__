// Problem Link :  https://leetcode.com/problems/maximum-swap/

class Solution {
    public int maximumSwap(int num) {
        char[] hehe = ("" + num).toCharArray();
        int n = hehe.length;
        int[] maxi = new int[n];

        maxi[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            int index = maxi[i + 1];
            if (hehe[i] > hehe[index])
                maxi[i] = i;
            else
                maxi[i] = index;

        }

        for (int i = 0; i < n; i++) {
            if (hehe[i] < hehe[maxi[i]]) {
                int index = maxi[i];
                char temp = hehe[i];
                hehe[i] = hehe[index];
                hehe[index] = temp;

                return Integer.parseInt(new String(hehe));
            }
        }
        return num;
    }
}
