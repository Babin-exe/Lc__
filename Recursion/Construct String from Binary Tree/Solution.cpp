// Problem Link : https://leetcode.com/problems/construct-string-from-binary-tree/description/

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
    string tree2str(TreeNode* root) {
        if (!root)
            return "";
        string hehe = to_string(root->val);
        string lf = tree2str(root->left);
        string rg = tree2str(root->right);

        if (!root->left && !root->right) {
            return hehe;
        }

        if (!root->right)
            return hehe + "(" + lf + ")";

        if (!root->left)
            return hehe + "()" + "(" + rg + ")";

        return hehe + "(" + lf + ")" + "(" + rg + ")";
    }
};
