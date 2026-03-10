// Problem Link : https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int left = solve(root->left);

        int right = solve(root->right);

        ans = max(ans, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
