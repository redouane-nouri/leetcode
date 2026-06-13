/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int eucMod(int a, int b) { return (a % b + abs(b)) % abs(b); };

ll encode(int a, int b) { return (ll)a << 32 | (unsigned int)b; }

/*
Computes (b^e) % m using binary exponentiation.

- b: base
- e: exponent (must be >= 0)
- m: modulo value

Returns: (b raised to power e) modulo m
Time complexity: O(log e)
*/
ll expo(ll b, ll e, const ll m) {
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

      if (!cur)
        break;

      node = cur;
    }

    // modify as needed
    return node->isEnd;
  }

  // implement the rest of functions as needed
};

class SegmentTree {
  int n;
  vector<int> tree;

  int merge(const int a, const int b) const {
    return max(a, b); // change to min or sum if needed
  }

  int identity() const {
    return INT_MIN; // INT_MAX for min, 0 for sum
  }

  void build(const int node, const int l, const int r,
             const vector<int> &data) {
    if (l == r) {
      tree[node] = data[l];
      return;
    }

    const int mid = (l + r) >> 1;

    build(node << 1, l, mid, data);
    build(node << 1 | 1, mid + 1, r, data);

    tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
  }

  int query(const int node, const int l, const int r, const int ql,
            const int qr) const {
    if (qr < l || r < ql)
      return identity();

    if (ql <= l && r <= qr)
      return tree[node];

    const int mid = (l + r) >> 1;

    return merge(query(node << 1, l, mid, ql, qr),
                 query(node << 1 | 1, mid + 1, r, ql, qr));
  }

  void update(const int node, const int l, const int r, const int idx,
              const int val) {
    if (l == r) {
      tree[node] = val;
      return;
    }

    const int mid = (l + r) >> 1;

    if (idx <= mid)
      update(node << 1, l, mid, idx, val);
    else
      update(node << 1 | 1, mid + 1, r, idx, val);

    tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
  }

public:
  SegmentTree(const vector<int> &data)
      : n(data.size()), tree(1 << (__lg(n - 1) + 2)) {
    build(1, 0, n - 1, data);
  }

  int query(const int l, const int r) const { return query(1, 0, n - 1, l, r); }

  void update(const int idx, const int val) { update(1, 0, n - 1, idx, val); }
};

class SparseTable {
  vector<vector<int>> table;

  int merge(const int a, const int b) const { return max(a, b); }

  void build(const vector<int> &data) {
    const int n = data.size(), m = __lg(n) + 1;
    table.assign(m, vector<int>(n));

    for (int i = 0; i < n; i++)
      table[0][i] = data[i];

    for (int i = 1; i < m; i++)
      for (int j = 0; j + (1 << i) <= n; j++)
        table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
  }

public:
  SparseTable(const vector<int> &data) { build(data); }

  int query(const int l, const int r) const {
    const int k = __lg(r - l + 1);

    return merge(table[k][l], table[k][r - (1 << k) + 1]);
  }
};

class LCA {
  vector<vector<int>> graph, ancestor;
  vector<int> depth;
  int ancestorMaxDepth;

  void calcDepth(const int node, const int parent) {
    ancestor[node][0] = parent;

    for (auto &neighbor : graph[node]) {
      if (neighbor == parent)
        continue;

      depth[neighbor] = depth[node] + 1;
      calcDepth(neighbor, node);
    }
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);

    for (int jump = ancestorMaxDepth - 1; jump >= 0; --jump)
      if (depth[u] <= depth[ancestor[v][jump]])
        v = ancestor[v][jump];

    if (u == v)
      return u;

    for (int jump = ancestorMaxDepth - 1; jump >= 0; --jump)
      if (ancestor[u][jump] != ancestor[v][jump])
        u = ancestor[u][jump], v = ancestor[v][jump];

    return ancestor[u][0];
  }

public:
  LCA(const vector<vector<int>> &edges) {
    const int numNodes = edges.size() + 1;
    ancestorMaxDepth = __lg(numNodes) + 1;

    // +1 because 1-indexed
    depth.resize(numNodes + 1);
    graph.resize(numNodes + 1);
    ancestor.resize(numNodes + 1, vector<int>(ancestorMaxDepth, 0));

    for (auto &e : edges)
      graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);

    calcDepth(1, 1);

    for (int jump = 1; jump < ancestorMaxDepth; ++jump)
      for (int u = 1; u <= numNodes; ++u)
        ancestor[u][jump] = ancestor[ancestor[u][jump - 1]][jump - 1];
  }

  int dist(const int u, const int v) {
    return depth[u] + depth[v] - (depth[lca(u, v)] << 1);
  }
};
