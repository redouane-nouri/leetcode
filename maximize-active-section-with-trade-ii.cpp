/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
  int n;
  vector<int> tree;

  int merge(const int a, const int b) const { return max(a, b); }

  int identity() const { return INT_MIN; }

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
      : n(data.size()), tree(1 << (__lg(max(n - 1, 1)) + 2)) {
    build(1, 0, n - 1, data);
  }

  int query(const int l, const int r) const { return query(1, 0, n - 1, l, r); }

  void update(const int idx, const int val) { update(1, 0, n - 1, idx, val); }
};

class Solution {
public:
  vector<int> maxActiveSectionsAfterTrade(string s,
                                          vector<vector<int>> &queries) {
    const int N = s.length(), onesCount = count(s.begin(), s.end(), '1');
    vector<int> zeroBlocks, blockLeft, blockRight;
    int i = 0;

    while (i < N) {
      int st = i++;

      while (i < N && s[i] == s[st])
        i += 1;

      if (s[st] == '0') {
        zeroBlocks.push_back(i - st);
        blockLeft.push_back(st);
        blockRight.push_back(i - 1);
      }
    }

    const int M = zeroBlocks.size();
    if (M < 2)
      return vector<int>(queries.size(), onesCount);

    vector<int> tmpSum(M - 1);
    for (int i = 0; i < M - 1; i++)
      tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];

    SegmentTree seg(tmpSum);
    vector<int> ans;

    for (const auto &q : queries) {
      int l = q[0], r = q[1];
      int i = lower_bound(blockRight.begin(), blockRight.end(), l) -
              blockRight.begin();

      int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) -
              blockLeft.begin() - 1;

      if (i > M - 1 || j < 0 || i >= j) {
        ans.push_back(onesCount);
        continue;
      }

      int firstLen = blockRight[i] - max(blockLeft[i], l) + 1,
          lastLen = min(blockRight[j], r) - blockLeft[j] + 1;

      if (i + 1 == j) {
        ans.push_back(onesCount + firstLen + lastLen);
        continue;
      }

      int val1 = firstLen + zeroBlocks[i + 1],
          val2 = zeroBlocks[j - 1] + lastLen, val3 = seg.query(i + 1, j - 2);

      ans.push_back(onesCount + max({val1, val2, val3}));
    }

    return ans;
  }
};
