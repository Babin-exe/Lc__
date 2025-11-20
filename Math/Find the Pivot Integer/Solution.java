// Problem Link : https://leetcode.com/problems/find-the-pivot-integer/?envType=problem-list-v2&envId=maths-m1-arithmetic-basic-reasoning

class Solution {
    public int pivotInteger(int n) {

        int sum = n * (n + 1) / 2;

        int temp = 0;
        for (int i = n; i >= 1; i--) {

            temp += i;
            if (temp == sum)
                return i;
            sum -= i;
        }
        return -1;

    }
}



