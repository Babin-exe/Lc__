// Problem Link : https://leetcode.com/problems/merge-two-binary-trees/description/


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
    public TreeNode solve(TreeNode root1, TreeNode root2) {

        if (root1 == null && root2 == null)
            return null;

        if (root1 == null) {
            return new TreeNode(root2.val, 
            solve(null, root2.left), solve(null, root2.right));
        }
        if (root2 == null) {
            return root1;
        }

        root1.val += root2.val;

        root1.left = solve(root1.left, root2.left);
        root1.right = solve(root1.right, root2.right);

        return root1;

    }

    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        return solve(root1, root2);
    }
}
