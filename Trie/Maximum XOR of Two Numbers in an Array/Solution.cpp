// Problem Link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
class TrieNode {
public:
    TrieNode* left;
    TrieNode* right;

    TrieNode() {
        left = nullptr;
        right = nullptr;
    }
};

void insert(TrieNode* root, int num) {
    TrieNode* crawl = root;
    for (int i = 31; i >= 0; i--) {
        int t = (num >> i) & 1;
        if (t == 1) {
            if (crawl->right == nullptr) {
                crawl->right = new TrieNode();
            }
            crawl = crawl->right;
        } else {
            if (crawl->left == nullptr) {
                crawl->left = new TrieNode();
            }
            crawl = crawl->left;
        }
    }
}

int findXor(TrieNode* root, int num) {
    int ans = 0;
    TrieNode* crawl = root;
    for (int i = 31; i >= 0; i--) {
        int t = (num >> i) & 1;
        if (t == 1) {
            if (crawl->left != nullptr) {
                ans += pow(2, i);
                crawl = crawl->left;
            } else {
                crawl = crawl->right;
            }
        } else {
            if (crawl->right != nullptr) {
                ans += pow(2, i);
                crawl = crawl->right;
            } else {
                crawl = crawl->left;
            }
        }
    }
    return ans;
}

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (auto& it : nums)insert(root, it);
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)ans = max(ans, findXor(root, nums[i]));
        return ans;
    }
};
