// Problem Link : https://leetcode.com/problems/fraction-addition-and-subtraction/description/

class Solution {

public:
    string fractionAddition(string e) {
        int n = e.length();
        int i = 0;

        int nume = 0;
        int deno = 1;
        bool isNegative = false;
        while (i < n) {
            int curr_nume = 0;
            int curr_deno = 0;

            isNegative = (e[i] == '-');

            if (e[i] == '+' || e[i] == '-')
                i++;

            while (i < n && isdigit(e[i])) {
                int num = e[i] - '0';
                curr_nume = (curr_nume * 10) + num;
                i++;
            }

            i++;

            while (i < n && isdigit(e[i])) {
                int num = e[i] - '0';
                curr_deno = (curr_deno * 10) + num;
                i++;
            }

            if (isNegative == true)
                curr_nume *= -1;
            nume = (nume * curr_deno) + (curr_nume * deno);
            deno = (curr_deno * deno);
        }

        int value = abs(__gcd(nume, deno));

        nume /= value;
        deno /= value;
        return to_string(nume) + "/" + to_string(deno);
    }
};
