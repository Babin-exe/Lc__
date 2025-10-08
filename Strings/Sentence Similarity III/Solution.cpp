// Problem Link : https://leetcode.com/problems/sentence-similarity-iii/

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.length() < sentence2.length())
            swap(sentence1, sentence2);

        vector<string> longer, small;

        stringstream ss(sentence1);
        string word;

        while (ss >> word) {
            longer.push_back(word);
        }

        stringstream take(sentence2);
        while (take >> word) {
            small.push_back(word);
        }

        int i = 0, j = longer.size() - 1;
        int l = 0, r = small.size() - 1;

        while (l <= r && longer[i] == small[l]) {
            i++;
            l++;
        }

        while (l <= r && longer[j] == small[r]) {
            j--;
            r--;
        }
        return l > r;
    }
};
