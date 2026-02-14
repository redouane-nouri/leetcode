#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
  struct SegmentTreeNode {
    int mi = 0;
    int mx = 0;
    int lz = 0;
  };
  const int N;
  vector<SegmentTreeNode> tree;

  void build(const vector<int> &d, const int l, const int r, const int i) {
    if (l == r) {
      tree[i].mi = tree[i].mx = d[l - 1];
      return;
    }

    int m = l + (r - l >> 1);

    build(d, l, m, i << 1);
    build(d, m + 1, r, i << 1 | 1);

    pushUp(i);
  }

  void pushUp(const int i) {
    tree[i].mi = min(tree[i << 1].mi, tree[i << 1 | 1].mi);
    tree[i].mx = max(tree[i << 1].mx, tree[i << 1 | 1].mx);
  }

  void pushDown(const int i) {
    if (tree[i].lz) {
      applyLazy(i << 1, tree[i].lz);
      applyLazy(i << 1 | 1, tree[i].lz);
      tree[i].lz = 0;
    }
  }

  void applyLazy(const int j, const int lz) {
    tree[j].mi += lz;
    tree[j].mx += lz;
    tree[j].lz += lz;
  }

public:
  SegmentTree(const vector<int> &d) : N(d.size()) {
    tree.resize(1 << (int)ceil(log2(N)) + 1);
    build(d, 1, N, 1);
  }

  void update(int start, int end, int value, int l, int r, int i) {
    if (start <= l && r <= end) {
      applyLazy(i, value);
      return;
    }

    pushDown(i);

    int m = l + (r - l >> 1);

    if (start <= m)
      update(start, end, value, l, m, i << 1);

    if (end > m)
      update(start, end, value, m + 1, r, i << 1 | 1);

    pushUp(i);
  }

  int find(const int start, int l, int r, int i) {
    if (tree[i].mi > 0 || tree[i].mx < 0)
      return -1;

    if (l == r)
      return l;

    pushDown(i);

    int m = l + (r - l >> 1);

    int res = find(start, m + 1, r, i << 1 | 1);

    if (res != -1)
      return res;

    if (m >= start)
      return find(start, l, m, i << 1);

    return -1;
  }
};

class Solution {
public:
  int longestBalanced(vector<int> &nums) {
    const int N = nums.size();
    const auto sign = [](int v) -> int { return v % 2 == 0 ? 1 : -1; };

    vector<int> pre(N);
    map<int, queue<int>> mp;

    pre[0] = sign(nums[0]);
    mp[nums[0]].push(1);

    for (int i = 1; i < N; ++i) {
      pre[i] = pre[i - 1];
      auto &q = mp[nums[i]];

      if (q.empty())
        pre[i] += sign(nums[i]);

      q.push(i + 1);
    }

    SegmentTree segTree(pre);
    int ans = 0;

    for (int i = 0; i < N; ++i) {
      ans = max(ans, segTree.find(i + ans + 1, 1, N, 1) - i);

      int end = N + 1;
      mp[nums[i]].pop();

      if (!mp[nums[i]].empty())
        end = mp[nums[i]].front();

      segTree.update(i + 1, end - 1, -sign(nums[i]), 1, N, 1);
    }

    return ans;
  }
};
