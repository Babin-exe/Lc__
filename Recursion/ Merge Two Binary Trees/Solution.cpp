// Problem Link : https://leetcode.com/problems/merge-two-binary-trees/description/

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
    TreeNode* solve(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return NULL;
        if (root1 == nullptr) {
            return new TreeNode(root2->val, solve(NULL, root2->left),
                                solve(NULL, root2->right));
        };
        if (root2 == nullptr) {
            return root1;
        };
        root1->val += root2->val;
        root1->left = solve(root1->left, root2->left);
        root1->right = solve(root1->right, root2->right);
        return root1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};
