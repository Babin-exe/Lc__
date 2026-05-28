// Problem Link : https://leetcode.com/problems/longest-common-suffix-queries/description/?envType=daily-question&envId=2026-05-28

class Solution {
public:
    class TrieNode {
    public:
        int idx;
        TrieNode* children[26];

        TrieNode() {
            idx = -1;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };
    class Trie {
    public:
        vector<string>* words;
        TrieNode* root;
        Trie(vector<string>& wordsContainer) {
            root = new TrieNode();
            words = &wordsContainer;
        }

        void clean(TrieNode* node) {
            if (node == nullptr)
                return;
            for (int i = 0; i < 26; i++)
                clean(node->children[i]);

            delete (node);
        }

        ~Trie() { clean(root); }

        bool check(int old, int neww) {
            if (old == -1)
                return true;

            int old_len = (*words)[old].length();
            int new_len = (*words)[neww].length();

            if (old_len != new_len) {
                return old_len > new_len;
            }

            return old > neww;
        }

        void updateIndex(TrieNode* current_node, int new_value) {
            if (check(current_node->idx, new_value)) {
                current_node->idx = new_value;
            }
        }

        void insert(int i, string& s) {

            TrieNode* crawl = root;

            updateIndex(crawl, i);

            for (int ii = s.length() - 1; ii >= 0; ii--) {
                int idx = s[ii] - 'a';
                if (crawl->children[idx] == NULL) {
                    crawl->children[idx] = new TrieNode();
                }
                crawl = crawl->children[idx];
                updateIndex(crawl, i);
            }
        }

        int searchTrie(int i, string& s) {
            TrieNode* crawl = root;
            for (int ii = s.length() - 1; ii >= 0; ii--) {
                int idx = s[ii] - 'a';
                if (crawl->children[idx] == nullptr) {
                    return crawl->idx;
                }
                crawl = crawl->children[idx];
            }
            return crawl->idx;
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        Trie trie(wordsContainer);

        for (int i = 0; i < wordsContainer.size(); i++) {
            trie.insert(i, wordsContainer[i]);
        }

        vector<int> ans;
        for (int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(trie.searchTrie(i, wordsQuery[i]));
        }
        return ans;
    }
};
