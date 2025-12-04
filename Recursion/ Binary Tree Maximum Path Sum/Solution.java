// Problem Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int sum;

    public int solve(TreeNode root) {
        if (root == null)
            return 0;

        int l = solve(root.left);
        int r = solve(root.right);
        int rv = root.val;

        int all = l + r + rv;
        int good = Math.max(l, r) + rv;

        sum = Math.max(Math.max(all, sum), Math.max(good, rv));

        return Math.max(good, rv);

    }

    public int maxPathSum(TreeNode root) {
        sum = Integer.MIN_VALUE;
        solve(root);
        return sum;
    }
}
