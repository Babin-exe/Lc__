// Problem Link : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description

class Solution {
public:
    int countOdds(int low, int high) {
        // int sum = 0;
        // if (high % 2 == 0)
        //     high--;

        // if (low % 2 == 0)
        //     low++;
        // sum += (high - low) / 2 + 1;
        // return sum;

        return (high + 1) / 2 - low / 2;
    }
};
