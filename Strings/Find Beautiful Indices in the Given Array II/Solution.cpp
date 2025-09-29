// Problem link : https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/description/

class Solution {

public:
    void makeLSP(string& pat, string& txt, vector<int>& LSP) {

        int m = pat.length();
        LSP[0] = 0;
        int i = 1;
        int length = 0;
        while (i < m) {

            if (pat[i] == pat[length]) {
                length++;
                LSP[i] = length;
                i++;
            } else {
                if (length == 0) {
                    i++;
                } else {
                    length = LSP[length - 1];
                }
            }
        }
    }

public:
    vector<int> KMP(string& pat, string& txt) {

        int m = pat.length();
        int n = txt.length();

        int i = 0, j = 0;

        vector<int> LSP(m, 0);
        vector<int> ans;

        makeLSP(pat, txt, LSP);

        while (i < n) {

            if (pat[j] == txt[i]) {
                i++;
                j++;
            }

            if (j == m) {
                ans.push_back(i - j);
                j = LSP[j - 1];
            }

            if (pat[j] != txt[i]) {

                if (j != 0) {
                    j = LSP[j - 1];
                } else {
                    i++;
                }
            }
        }
        return ans;
    }

public:
    int lowerBound(vector<int>& LSP_B, int target) {
        int s = 0;
        int e = LSP_B.size() - 1;
        int ans = LSP_B.size();
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (LSP_B[mid] >= target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        vector<int> LSP_A = KMP(a, s);
        vector<int> LSP_B = KMP(b, s);

        vector<int> result;

        for (int& val : LSP_A) {
            int lower_Bound = max(0, val - k);
            int upper_Bound = min(n - 1, val + k);

            int idx = lowerBound(LSP_B, lower_Bound);
            if (idx < LSP_B.size()) {
                int take = LSP_B[idx];
                if (take <= upper_Bound) {
                    result.push_back(val);
                }
            }
        }
        return result;
    }
};
