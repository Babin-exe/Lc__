// Problem Link : https://leetcode.com/problems/binary-tree-cameras/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 Time: O(n) — proportional to all nodes visited
 Space: O(h) — proportional to maximum recursion depth
 */

class Solution {
public:
    int count = 0;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 2;

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == 0 || right == 0) {
            count++;
            return 1;
        }

        if (left == 1 || right == 1) {
            return 2;
        }

        return 0;
    }

    int minCameraCover(TreeNode* root) {
        if (solve(root) == 0)
            count++;
        return count;
    }
};
