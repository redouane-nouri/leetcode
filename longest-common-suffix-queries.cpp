/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

struct TrieNode {
    char c;
    TrieNode *child;
    TrieNode *next;
    int bestIdx;
    TrieNode(char c = '\0') : c(c), child(nullptr), next(nullptr), bestIdx(-1) {}
};

class Trie {
    TrieNode *root;

    void updateBest(TrieNode *node, int idx, vector<string>& wc) {
        if (node->bestIdx == -1 || wc[idx].size() < wc[node->bestIdx].size())
            node->bestIdx = idx;
    }

public:
    Trie() { root = new TrieNode(); }

    void insert(int idx, vector<string>& wc) {
        const string &s = wc[idx];
        TrieNode *node = root;

        updateBest(node, idx, wc);

        for (int i = s.size() - 1; i >= 0; --i) {
            TrieNode *cur = node->child;

            while (cur && cur->c != s[i])
                cur = cur->next;

            if (!cur) {
                cur = new TrieNode(s[i]);
                cur->next = node->child;
                node->child = cur;
            }

            updateBest(cur, idx, wc);
            node = cur;
        }
    }

    int query(const string &s) {
        TrieNode *node = root;

        for (int i = s.size() - 1; i >= 0; --i) {
            TrieNode *cur = node->child;

            while (cur && cur->c != s[i])
                cur = cur->next;

            if (!cur) break;

            node = cur;
        }

        return node->bestIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;

        for (int i = 0; i < wordsContainer.size(); ++i)
            trie.insert(i, wordsContainer);

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (auto& q : wordsQuery)
            ans.push_back(trie.query(q));

        return ans;
    }
};
