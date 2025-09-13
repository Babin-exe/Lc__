// Problem link : https://leetcode.com/problems/repeated-substring-pattern/
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();

        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0)
                continue;

            String auh = s.substring(0, i);
            StringBuilder ans = new StringBuilder("");

            for (int j = 0; j < n / i; j++) {
                ans.append(auh);
            }
            if (ans.toString().equals(s))
                return true;

        }

        return false;
    }
}

// I don't know about these approaches 

//Approach 1 : 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, t.size() - 2).find(s) != string::npos;
    }
};



//Approach 2 : 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> pi(n, 0);
        
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }

        int lps = pi[n - 1]; // longest proper prefix also suffix
        return lps > 0 && n % (n - lps) == 0;
    }
};

//Approach 3 : 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0) continue;

            string sub = s.substr(0, i);
            string ans;
            ans.reserve(n); // avoid reallocation

            for (int j = 0; j < n / i; j++) {
                ans.append(sub);
            }

            if (ans == s) return true;
        }
        return false;
    }
};





