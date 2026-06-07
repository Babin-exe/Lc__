// Problem Link : https://leetcode.com/problems/create-binary-tree-from-descriptions/description/


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
#include <bits/stdc++.h>
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, TreeNode*> mp;
        unordered_set<int> ump;
        int n = d.size();
        for (int i = 0; i < n; i++) {

            int parent = d[i][0];
            int child = d[i][1];
            int left = d[i][2];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }
            
            ump.insert(child);

            if (left == 1) {
                mp[parent]->left = mp[child];

            } else {
                mp[parent]->right = mp[child];
            }
        }

        for (int i = 0; i < n; i++) {
            int parent = d[i][0];
            if (ump.find(parent) == ump.end()) {
                return mp[parent];
            }
        }

        return NULL;
    }
};
