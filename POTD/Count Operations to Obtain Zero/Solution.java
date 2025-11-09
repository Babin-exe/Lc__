// Problem Link : https://leetcode.com/problems/count-operations-to-obtain-zero/description/

class Solution {
    public int countOperations(int num1, int num2) {
        int count = 0;
        if (num1 == 0 || num2 == 0) {
            return count;
        }
        while (true) {

            if (num1 >= num2) {
                num1 = num1 - num2;
                count++;
                if (num1 == 0)
                    break;
            } else {
                num2 = num2 - num1;
                count++;
                if (num2 == 0)
                    break;
            }
        }
        return count;
    }
}
