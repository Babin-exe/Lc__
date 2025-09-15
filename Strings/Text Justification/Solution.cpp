// Problem link : https://leetcode.com/problems/text-justification/
class Solution {


    string getLine(int i, int j, int rem_holes, int each_hole, int extra_hole,
                   vector<string>& words, int maxWidth) {

        string hehe;

        for (int a = i; a < j; a++) {
            hehe += words[a];
            if (a == j - 1)
                continue;
            for (int b = 1; b <= each_hole; b++) {
                hehe += " ";
            }
            if (extra_hole > 0) {
                hehe += " ";
                extra_hole--;
            }
        }
        while (hehe.length() < maxWidth) {
            hehe += " ";
        }
        return hehe;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        int n = words.size();
        while (i < n) {
            int lc = words[i].length();
            int j = i + 1;
            int holes = 0;
            while (j < n && lc + words[j].length() + 1 + holes <= maxWidth) {
                lc += words[j].length();
                holes++;
                j++;
            }
            int rem_holes = maxWidth - lc;
            int each_hole = holes == 0 ? 0 : rem_holes / holes;
            int extra_hole = holes == 0 ? 0 : rem_holes % holes;
            if (j == n) {
                each_hole = 1;
                extra_hole = 0;
            }
            ans.push_back(getLine(i, j, rem_holes, each_hole, extra_hole, words,
                                  maxWidth));
            i = j;
        }

        return ans;
    }
};
