// Problem Link : https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/description/
class Solution {
    public List<Integer> findGoodIntegers(int n) {
        Map<Long, Integer> mp = new HashMap<>();
        for (int i = 1; i <= 1000; i++) {
            long isum = (long) i * i * i;
            if (isum > n)
                break;
            for (int j = i; j <= 1000; j++) {
                long jsum = (long) j * j * j;
                long tsum = isum + jsum;
                if (tsum > n)
                    break;
                mp.put(tsum, mp.getOrDefault(tsum, 0) + 1);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (Map.Entry<Long, Integer> mpp : mp.entrySet()) {
            if (mpp.getValue() >= 2)
                ans.add(mpp.getKey().intValue());
        }
        Collections.sort(ans);
        return ans;
    }
}
