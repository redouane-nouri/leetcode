/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int eucMod(int a, int b) { return (a % b + abs(b)) % abs(b); };

ll encode(int a, int b) { return (ll)a << 32 | (unsigned int)b; }

ll expo(ll b, ll e, ll m) {
  ll r = 1;

  while (e) {
    if (e & 1)
      r = r * b % m;

    b = b * b % m;
    e >>= 1;
  }

  return r;
}

ll inv(ll v, ll m) { return expo(v, m - 2, m); }

struct DSU {
  vector<int> parent, size;

  DSU(const int n) : parent(n), size(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(const int u) {
    if (parent[u] == u)
      return u;

    return parent[u] = find(parent[u]);
  }

  void unite(int u, int v) {
    u = find(u), v = find(v);

    if (u != v) {
      if (size[u] < size[v])
        swap(u, v);

      parent[v] = u;
      size[u] += size[v];
    }
  }
};

struct TrieNode {
    char c;
    TrieNode *child;
    TrieNode *next;
    bool isEnd;
    TrieNode(char c = '\0') : c(c), child(nullptr), next(nullptr), isEnd(false) {}
};

class Trie {
    TrieNode *root;
public:
    Trie() { root = new TrieNode(); }

    void insert(const string &s) {
        TrieNode *node = root;

        for (const char &c : s) {
            TrieNode *cur = node->child;

            while (cur && cur->c != c)
                cur = cur->next;

            if (!cur) {
                cur = new TrieNode(c);
                cur->next = node->child;
                node->child = cur;
            }

            node = cur;
        }

        node->isEnd = true;
    }

    bool query(const string &s) {
        TrieNode *node = root;

        for (int i = 0; i < s.size(); ++i) {
            TrieNode *cur = node->child;

            while (cur && cur->c != s[i])
                cur = cur->next;

            if (!cur) break;

            node = cur;
        }

        //modify as needed
        return node->isEnd;
    }

    //implement the rest of functions as needed
};
