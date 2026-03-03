// Problem Link : https://leetcode.com/problems/merge-close-characters/description/

/*
Though process :

If we see a character for the first time we can simply put it somewhere lets say
a vector

but if we see it again what should we do ????

we will check if the last seen - the current index i am looking from <=k if yes

 that means that character is to be removed okay lets remove it
string.erase(i,1);

 now what ? how do we handle the shifting of the string ??

 lets say the deleted string is our new string and we will start the process
again with this new string

This is not so optimal but fine becasue n is given as 100 so at max we go 100 * 100 



*/

class Solution {
public:
    string mergeCharacters(string s, int k) {

        bool hehe = true;
        while (hehe) {
            hehe = false;
            string a = s;
            int n = s.length();
            vector<int> fq(26, -1);
            for (int i = 0; i < n; i++) {
                char ch = s[i];
                if (fq[ch - 'a'] != -1 && i - fq[ch - 'a'] <= k) {
                    a.erase(i, 1);
                    s = a;
                    hehe = true;
                    break;
                } else {
                    fq[ch - 'a'] = i;
                }
            }
            if (!hehe)
                return s;
        }
        return s;
    }
};
