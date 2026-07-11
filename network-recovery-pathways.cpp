/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
                       long long k) {
    const int N = online.size();
    vector<vector<pair<int, int>>> g(N);
    int l = INT_MAX, r = 0;

    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];

      if (online[u] && online[v])
        g[u].push_back({v, w}), l = min(l, w), r = max(r, w);
    }

    const auto check = [&N, &k, &g](int minW) -> bool {
      vector<long long> memo(N, -1);

      auto dfs = [&N, &memo, &minW, &g](this auto &&dfs, int u) -> long long {
        if (u == N - 1)
          return 0;

        if (memo[u] != -1)
          return memo[u];

        long long res = LLONG_MAX >> 1;

        for (auto &[v, w] : g[u])
          if (w >= minW)
            res = min(res, dfs(v) + w);

        memo[u] = res;
        return memo[u];
      };

      return dfs(0) <= k;
    };

    if (!check(l))
      return -1;

    while (l <= r) {
      int m = l + (r - l >> 1);

      if (check(m))
        l = m + 1;
      else
        r = m - 1;
    }

    return r;
  }
};
