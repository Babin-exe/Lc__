// Problem link : https://leetcode.com/problems/count-beautiful-substrings-ii/
import java.util.*;

class Solution {

    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public long beautifulSubstrings(String s, int k) {
        long result = 0;
        long vowel = 0;
        long consonant = 0;


        Map<Long, Map<Long, Long>> mp = new HashMap<>();
        mp.put(0L, new HashMap<>());
        mp.get(0L).put(0L, 1L);

        for (char ch : s.toCharArray()) {

            if (isVowel(ch))
                vowel++;
            else
                consonant++;

            long ps = vowel - consonant;

            mp.putIfAbsent(ps, new HashMap<>());
            Map<Long, Long> inner = mp.get(ps);


            for (Map.Entry<Long, Long> entry : inner.entrySet()) {
                long pastVowel = entry.getKey();
                long count = entry.getValue();

                if (((vowel % k - pastVowel) * (vowel % k - pastVowel)) % k == 0)
                    result += count;
            }
            inner.put(vowel % k, inner.getOrDefault(vowel % k, 0L) + 1);
        }

        return result;
    }
}
