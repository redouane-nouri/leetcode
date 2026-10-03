/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
  struct Node {
    array<int, 5> ways;
    int rem;
  };
  int n, k;
  vector<Node> tree;

  Node merge(const Node &a, const Node &b) const {
    Node res = a;

    for (int r = 0; r < k; ++r)
      res.ways[r * res.rem % k] += b.ways[r];

    res.rem = a.rem * b.rem % k;
    return res;
  }

  Node identity() const {
    Node id;
    id.ways.fill(0), id.rem = 1 % k;
    return id;
  }

  void build(const int &node, const int &l, const int &r,
             const vector<int> &data) {
    if (l == r) {
      tree[node].rem = data[l] % k;
      tree[node].ways.fill(0);
      tree[node].ways[tree[node].rem] = 1;
      return;
    }

    const int mid = (l + r) >> 1;

    build(node << 1, l, mid, data);
    build(node << 1 | 1, mid + 1, r, data);

    tree[node] = merge(tree[node << 1], tree[node << 1 | 1]);
  }

  Node query(const int &node, const int &l, const int &r, const int &ql,
             const int &qr) const {
    if (qr < l || r < ql)
      return identity();

    if (ql <= l && r <= qr)
      return tree[node];

    const int mid = (l + r) >> 1;

    return merge(query(node << 1, l, mid, ql, qr),
                 query(node << 1 | 1, mid + 1, r, ql, qr));
  }

  void update(const int &node, const int &l, const int &r, const int &idx,
              const int &val) {
    if (l == r) {
      tree[node].ways[tree[node].rem] = 0;
      tree[node].rem = val % k;
      tree[node].ways[tree[node].rem] = 1;
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
  SegmentTree(const vector<int> &data, int k)
      : k(k), n(data.size()), tree(1 << (__lg(max(n - 1, 1)) + 2)) {
    build(1, 0, n - 1, data);
  }

  Node query(const int &l) const { return query(1, 0, n - 1, l, n - 1); }

  void update(const int &idx, const int &val) { update(1, 0, n - 1, idx, val); }
};

class Solution {
public:
  vector<int> resultArray(vector<int> &nums, int k,
                          vector<vector<int>> &queries) {
    SegmentTree seg(nums, k);

    vector<int> res;
    res.reserve(queries.size());

    for (auto &q : queries) {
      int &idx = q[0], val = q[1], start = q[2], x = q[3];
      seg.update(idx, val);
      res.push_back(seg.query(start).ways[x]);
    }

    return res;
  }
};
