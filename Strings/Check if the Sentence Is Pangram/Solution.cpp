// Problem link :https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

class Solution {
public:
    bool checkIfPangram(string sentence) {

        if (sentence.size() < 26)
            return false;
        int count = 0;
        vector<int> chars(26, 0);
        for (char &ch : sentence) {
            int idx = ch - 'a';
            if (chars[idx] == 0) {
                count++;
                chars[idx]++;
            }
        }
        return count == 26;
    }
};



