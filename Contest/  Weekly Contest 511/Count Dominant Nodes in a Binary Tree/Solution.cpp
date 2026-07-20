// Problem Link : https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/
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
    int ans = 0;
    int solve(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int left = solve(root->left);
        int curr = root->val;
        int right = solve(root->right);

        if (curr >= left && curr >= right) {
            ans++;
        }

        return max({left, right, curr});
    }

    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;
    }
};
