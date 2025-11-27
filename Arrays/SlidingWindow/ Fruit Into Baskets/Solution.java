// Problem Link : https://leetcode.com/problems/fruit-into-baskets/

class Solution {
    public int totalFruit(int[] fruits) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        int n = fruits.length;
        int count = 0;
        while (j < n) {
            mp.put(fruits[j], mp.getOrDefault(fruits[j], 0) + 1);
            if (mp.size() <= 2) {
                count = Math.max(j - i + 1, count);
            } else {
                mp.put(fruits[i], mp.getOrDefault(fruits[i], 0) - 1);
                if (mp.get(fruits[i]) == 0) {
                    mp.remove(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return count;

    }
}
