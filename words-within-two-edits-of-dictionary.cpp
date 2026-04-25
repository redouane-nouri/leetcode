/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
  TrieNode *child[26] = {nullptr};
  bool isEnd = false;
};

class Trie {

public:
  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(const string &s) {
    TrieNode *node = root;

    for (const char &c : s) {
      int i = c - 'a';

      if (!node->child[i])
        node->child[i] = new TrieNode();

      node = node->child[i];
    }

    node->isEnd = true;
  }

  bool search(const string &w, int i, TrieNode *node, int c) {
    if (c > 2 || !node)
      return false;

    if (i == w.size())
      return node->isEnd;

    int idx = w[i] - 'a';

    if (node->child[idx])
      if (search(w, i + 1, node->child[idx], c))
        return true;

    if (c < 2)
      for (int j = 0; j < 26; j++)
        if (j != idx && node->child[j])
          if (search(w, i + 1, node->child[j], c + 1))
            return true;

    return false;
  }
};

class Solution {
public:
  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {
    Trie trie;

    for (auto &w : dictionary)
      trie.insert(w);

    vector<string> ans;

    for (auto &q : queries)
      if (trie.search(q, 0, trie.root, 0))
        ans.push_back(q);

    return ans;
  }
};
