// Problem Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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

    public int finder(TreeNode root, int idx) {
        if (root == null)
            return idx;
        idx += 1;
        if (root.left == null && root.right == null) {
            return idx;
        }

        int left = finder(root.left, idx);
        int right = finder(root.right, idx);
        return Math.max(left, right);
    }

    public int maxDepth(TreeNode root) {
        int idx = 0;
        int val = 0;
        val = finder(root, idx);
        return val;

    }
}
