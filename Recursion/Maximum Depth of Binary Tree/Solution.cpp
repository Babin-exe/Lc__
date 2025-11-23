// Problem Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
 */
class Solution {
public:
    int solve(TreeNode* root, int idx) {
        if (root == NULL)
            return false;

        idx += 1;

        if (root->left == NULL && root->right == NULL) {
            return idx;
        }

        int l = solve(root->left, idx);
        int r = solve(root->right, idx);
        return max(l, r);
    }

    int maxDepth(TreeNode* root) {
        int idx = 0;
        int val = solve(root, idx);
        return val;
    }
};
