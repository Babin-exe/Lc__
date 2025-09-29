// Problem link : https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/
import java.util.*;

class Solution {
    public void makeLSP(String pat, int[] LSP) {
        int m = pat.length();
        LSP[0] = 0;
        int i = 1;
        int length = 0;

        while (i < m) {
            if (pat.charAt(i) == pat.charAt(length)) {
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

    public List<Integer> KMP(String pat, String txt) {
        int m = pat.length();
        int n = txt.length();
        int i = 0, j = 0;

        int[] LSP = new int[m];
        List<Integer> ans = new ArrayList<>();

        makeLSP(pat, LSP);

        while (i < n) {
            if (pat.charAt(j) == txt.charAt(i)) {
                i++;
                j++;
            }

            if (j == m) {
                ans.add(i - j);
                j = LSP[j - 1];
            }

            if (i < n && pat.charAt(j) != txt.charAt(i)) {
                if (j != 0) {
                    j = LSP[j - 1];
                } else {
                    i++;
                }
            }
        }

        return ans;
    }

    public int lowerBound(List<Integer> LSP_B, int target) {
        int s = 0;
        int e = LSP_B.size() - 1;
        int ans = LSP_B.size();

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (LSP_B.get(mid) >= target) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }

    public List<Integer> beautifulIndices(String s, String a, String b, int k) {
        int n = s.length();

        List<Integer> LSP_A = KMP(a, s);
        List<Integer> LSP_B = KMP(b, s);

        List<Integer> result = new ArrayList<>();

        for (int val : LSP_A) {
            int lower_Bound = Math.max(0, val - k);
            int upper_Bound = Math.min(n - 1, val + k);

            int idx = lowerBound(LSP_B, lower_Bound);
            if (idx < LSP_B.size()) {
                int take = LSP_B.get(idx);
                if (take <= upper_Bound) {
                    result.add(val);
                }
            }
        }

        return result;
    }
}

