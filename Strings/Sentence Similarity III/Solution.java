// Problem Link : https://leetcode.com/problems/sentence-similarity-iii/
class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {

        int m = sentence1.length();
        int n = sentence2.length();
        if (m < n) {
            String temp = sentence1;
            sentence1 = sentence2;
            sentence2 = temp;
        }

        String[] longer = sentence1.split(" ");
        String[] shorter = sentence2.split(" ");
        int i = 0, j = longer.length - 1;
        int l = 0, r = shorter.length - 1;

        while (l <= r && shorter[l].equals(longer[i])) {

            l++;
            i++;

        }
        while (l <= r && shorter[r].equals(longer[j])) {

            r--;
            j--;

        }
        return l > r;

    }
}
