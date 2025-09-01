// Problem link : https://leetcode.com/problems/string-compression/submissions/1755422853/
class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int i = 0;
        int index = 0;

        while (i < n) {
            char current_char = chars[i];
            int count = 0;

            while (i < n && chars[i] == current_char) {
                count++;
                i++;
            }
            chars[index] = current_char;
            index++;

            if (count > 1) {
                string taker = to_string(count);
                for (char& take : taker) {
                    chars[index] = take;
                    index++;
                }
            }
        }

        return index;
    }
};
