// Problem Link : https://leetcode.com/problems/symmetric-tree/

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
    bool solve(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if ((left->val == right->val) && solve(left->left, right->right) &&
            solve(left->right, right->left))
            return true;

        return false;
    }

    bool isSymmetric(TreeNode* root) { return solve(root->left, root->right); }
};
