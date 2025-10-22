// Problem Link : https://leetcode.com/problems/add-strings/description/

class Solution {
public:
    string addStrings(string num1, string num2) {

        string result = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;

            int sum = x + y + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
