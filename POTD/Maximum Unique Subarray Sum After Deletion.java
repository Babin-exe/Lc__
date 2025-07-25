// Problem link: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25

// java  solution , i might add c++ ,later ,i guessss😔: 
class Solution {
    public int maxSum(int[] nums) {
        //okayayayay i see that we can delete all the stuff of the array
        //as long as i dont make it completely empty 
        //lets thinklkkkkk
        int neg = Integer.MIN_VALUE;
        HashSet<Integer> set = new HashSet<Integer>();
        int sum = 0;

        for (int take : nums) {
            if (take <= 0) {
                //first i check if the num is negative
                //if it is all i do is try to find the most big negative 
                neg = Math.max(neg, take);
            } else if (!set.contains(take)) {
                //if we dont have negative then i just try to 
                //find unique num that i want to add in my sum
                set.add(take);
                sum += take;
            }

        }

        // now if no element was added in the sum then it would be 0 i guess

        return sum == 0 ? neg : sum;
    }
}
