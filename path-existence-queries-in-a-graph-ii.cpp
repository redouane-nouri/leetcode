/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class BinaryLifting {
  vector<vector<int>> up;

  void build(const vector<int> &next) {
    const int N = next.size(), M = __lg(N) + 1;

    up.assign(M, vector<int>(N));
    up[0] = next;

    for (int i = 1; i < M; ++i)
      for (int j = 0; j < N; ++j)
        up[i][j] = up[i - 1][up[i - 1][j]];
  }

public:
  BinaryLifting(const vector<int> &next) { build(next); }

  int query(const int from, const int to) const {
    if (from == to)
      return 0;

    int cur = from, jumps = 0;

    for (int i = up.size() - 1; i >= 0; --i)
      if (up[i][cur] < to)
        jumps += 1 << i, cur = up[i][cur];

    return (up[0][cur] >= to) ? jumps + 1 : -1;
  }
};

class Solution {
public:
  vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                   vector<vector<int>> &queries) {
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a, int b) { return nums[a] < nums[b]; });

    vector<int> sortedVal(n), pos(n);
    for (int i = 0; i < n; ++i)
      sortedVal[i] = nums[order[i]], pos[order[i]] = i;

    vector<int> maxJumps(n);
    int r = 0;

    for (int i = 0; i < n; ++i) {
      if (r < i)
        r = i;

      while (r + 1 < n && sortedVal[r + 1] - sortedVal[i] <= maxDiff)
        ++r;

      maxJumps[i] = r;
    }

    BinaryLifting bl(maxJumps);

    vector<int> ans(queries.size());

    for (int i = 0; i < queries.size(); ++i) {
      int p = pos[queries[i][0]], q = pos[queries[i][1]];

      if (p > q)
        swap(p, q);

      ans[i] = bl.query(p, q);
    }

    return ans;
  }
};
