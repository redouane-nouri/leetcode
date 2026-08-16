/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int len = 0, pre = 0, suf = 0, best = 0;
  char leftCh = 0, rightCh = 0;
};

class SegmentTree {
  int n;
  vector<Node> tree;
  string s;

  Node merge(const Node &a, const Node &b) const {
    Node res = {a.len + b.len,       a.pre,    b.suf,
                max(a.best, b.best), a.leftCh, b.rightCh};

    if (a.pre == a.len && a.rightCh == b.leftCh)
      res.pre += b.pre;

    if (b.suf == b.len && b.leftCh == a.rightCh)
      res.suf += a.suf;

    if (a.rightCh == b.leftCh)
      res.best = max(res.best, a.suf + b.pre);

    return res;
  }

  void build(int node, int l, int r) {
    if (l == r) {
      tree[node] = {1, 1, 1, 1, s[l], s[l]};
      return;
    }

    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
    tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
  }

  void update(int node, int l, int r, int idx, char val) {
    if (l == r) {
      tree[node] = {1, 1, 1, 1, val, val};
      return;
    }

    int mid = (l + r) >> 1;
    if (idx <= mid)
      update(node << 1, l, mid, idx, val);
    else
      update(node << 1 | 1, mid + 1, r, idx, val);

    tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
  }

public:
  SegmentTree(const string &data)
      : n(data.size()), s(data), tree(1 << (__lg(max(n - 1, 1)) + 2)) {
    build(1, 0, n - 1);
  }

  void update(int idx, char val) {
    s[idx] = val;
    update(1, 0, n - 1, idx, val);
  }

  int queryBest() const { return tree[1].best; }
};

class Solution {
public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int> &queryIndices) {
    SegmentTree st(s);
    const int k = queryCharacters.size();
    vector<int> ans(k);

    for (int i = 0; i < k; i++)
      st.update(queryIndices[i], queryCharacters[i]), ans[i] = st.queryBest();

    return ans;
  }
};
