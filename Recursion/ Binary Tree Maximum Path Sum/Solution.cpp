// Problem Link : https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int sum;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        int all_explored = left + right + root->val;
        int better_explore = max(left, right) + root->val;
        int only_root = root->val;

        sum = max({sum, all_explored, better_explore, only_root});

        return max(only_root, better_explore);
    }
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        solve(root);
        return sum;
    }
};
