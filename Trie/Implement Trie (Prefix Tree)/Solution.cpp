// Problem Link : https://leetcode.com/problems/implement-trie-prefix-tree/description/
class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* crawl = root;
        for (char c : word) {
            int id = c - 'a';

            if (crawl->children[id] == NULL) {
                crawl->children[id] = new TrieNode();
            }
            crawl = crawl->children[id];
        }
        crawl->isEnd = true;
    }

    bool search(string word) {
        TrieNode* crawl = root;
        for (char c : word) {
            int id = c - 'a';
            if (crawl->children[id] == NULL) {
                return false;
            }
            crawl = crawl->children[id];
        }
        return crawl->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* crawl = root;
        for (char c : prefix) {
            int id = c - 'a';
            if (crawl->children[id] == NULL)
                return false;
            crawl = crawl->children[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
