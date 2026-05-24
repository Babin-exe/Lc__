// Problem Link : https://leetcode.com/problems/password-strength/description/

class Solution {
public:
    int passwordStrength(string p) {
        set<char> st;
        for (char ch : p) {
            st.insert(ch);
        }

        int ans = 0;

        for (auto& it : st) {

            if (it >= 'a' && it <= 'z')
                ans++;
            else if (it >= 'A' && it <='Z')
                ans += 2;
            else if (it >= '0' && it <= '9')
                ans += 3;
            else if (it == '!' || it == '@' || it == '#' || it == '$')
                ans += 5;
        }
        return ans;
    }
};
