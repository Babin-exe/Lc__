// Problem Link : https://leetcode.com/problems/path-sum/description/


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean solve(TreeNode root, int targetSum, int sum) {
        if (root == null)
            return false;

        sum += root.val;

        if (root.left == null && root.right == null) {
            if (targetSum == sum)
                return true;
            return false;
        }

        boolean l = solve(root.left, targetSum, sum);
        boolean r = solve(root.right, targetSum, sum);
        if (l || r)
            return true;
        return false;
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        int sum = 0;

        boolean ans = solve(root, targetSum, sum);
        return ans;

    }
}
