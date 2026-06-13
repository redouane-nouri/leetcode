/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

class Solution {
public:
  ll maxTotalValue(vector<int> &nums, int k) {
    const int N = nums.size();
    vector<int> neg(N);

    transform(nums.begin(), nums.end(), neg.begin(), negate<int>());

    SparseTable mx(nums), mn(neg);
    priority_queue<tuple<int, int, int>> pq;

    for (int l = 0; l < N; ++l)
      pq.emplace(mx.query(l, N - 1) + mn.query(l, N - 1), l, N - 1);

    ll ans = 0;
    while (k--) {
      auto [v, l, r] = pq.top();
      pq.pop();
      ans += v;

      if (l < r)
        pq.emplace(mx.query(l, r - 1) + mn.query(l, r - 1), l, r - 1);
    }

    return ans;
  }
};
