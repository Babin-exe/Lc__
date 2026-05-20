// Problem Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = B.size(), count = 0;
        vector<int> r(n);
        map<int, int> ct;

        for (int i = 0; i < n; i++) {

            count += ct[A[i]];
            ct[A[i]]++;

            count +=ct[B[i]];
            ct[B[i]]++;

            r[i] = count;
        }

        return r;
    }
};
