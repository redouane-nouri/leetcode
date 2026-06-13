/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  static constexpr int mod = 1e9 + 7;

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

  int getDepth(const int node, const int parent, vector<vector<int>> &g) {
    int d = 0;

    for (const int &child : g[node])
      if (child != parent)
        d = max(d, 1 + getDepth(child, node, g));

    return d;
  }

public:
  int assignEdgeWeights(vector<vector<int>> &edges) {
    vector<vector<int>> g(edges.size() + 2);

    for (auto &e : edges)
      g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

    int d = getDepth(1, -1, g);
    return expo(2, d - 1, mod);
  }
};
