// Problem link :https://leetcode.com/problems/sort-vowels-in-a-string/ 
class Solution {

    public boolean isVowel(char ch) {
        return "aeiouAEIOU".indexOf(ch) != -1;
    }

    public String sortVowels(String s) {
        StringBuilder hehe = new StringBuilder(s);
        List<Character> vowel = new ArrayList<>();
        List<Integer> index = new ArrayList<>();
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (isVowel(ch)) {
                vowel.add(ch);
                index.add(i);
            }
        }
        Collections.sort(vowel);
        for (int i = 0; i < vowel.size(); i++) {
            hehe.setCharAt(index.get(i), vowel.get(i));
        }
        return hehe.toString();
    }
}
