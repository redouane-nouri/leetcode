/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minScore(int n, vector<vector<int>> &roads) {
    vector<vector<pair<int, int>>> g(n + 1);
    for (auto &r : roads) {
      g[r[0]].push_back({r[1], r[2]});
      g[r[1]].push_back({r[0], r[2]});
    }

    vector<bool> vi(n + 1, false);

    queue<int> q;
    int ans = INT_MAX;

    q.push(1);
    vi[1] = true;
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto &[v, d] : g[u]) {
        ans = min(ans, d);

        if (!vi[v])
          vi[v] = true, q.push(v);
      }
    }

    return ans;
  }
};
