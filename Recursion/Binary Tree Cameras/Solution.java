// Problem Link : https://leetcode.com/problems/binary-tree-cameras/

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
Tc: O(n)
Sc : O(n)
 */
class Solution {
    //Here 2 = covered , 1 = has the camera itself , 0 = needs the camera 
    int count = 0;

    public int solve(TreeNode root) {
        if (root == null)
            return 2;

        int left = solve(root.left);
        int right = solve(root.right);

        if (left == 0 || right == 0) {
            count++;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }

        return 0;

    }

    public int minCameraCover(TreeNode root) {

        if (solve(root) == 0)
            count++;
        return count;

    }
}
