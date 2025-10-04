// Problem link :https://leetcode.com/problems/find-the-closest-palindrome/description/

class Solution {

public:
    void makeStuff(long num, vector<long>& stuff, bool isOdd) {
        long hehe = num;
        if (isOdd == true)
            num /= 10;

        while (num > 0) {
            long modu = num % 10;
            hehe = (hehe * 10) + modu;
            num /= 10;
        }
        stuff.push_back(hehe);
    }

public:
    string nearestPalindromic(string n) {
        int l = n.length();
        int mid = l % 2 == 0 ? l / 2 : l / 2 + 1;
        vector<long> stuff;

        int sub = stol(n.substr(0, mid));

        makeStuff(sub, stuff, l % 2 != 0);
        makeStuff(sub + 1, stuff, l % 2 != 0);
        makeStuff(sub - 1, stuff, l % 2 != 0);

        stuff.push_back((long)pow(10, l) + 1);
        stuff.push_back((long)pow(10, l - 1) - 1);

        long ans = -1;
        long min_check = LONG_MAX;
        long original = stol(n);
        for (long taker : stuff) {
            if (taker == original)
                continue;
            long diff = abs(original - taker);
            if (min_check > diff || (min_check == diff && ans > taker)) {
                min_check = diff;
                ans = taker;
            }
        }
        return to_string(ans);
    }
};
