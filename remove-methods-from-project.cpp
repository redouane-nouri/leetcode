/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations) {
    vector<vector<int>> adj(n);
    vector<int> invoked(n, 0);
    vector<bool> susp(n, false);

    for (auto &inv : invocations) {
      adj[inv[0]].push_back(inv[1]);
      ++invoked[inv[1]];
    }

    queue<int> q;
    q.push(k);
    susp[k] = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int &v : adj[u]) {
        --invoked[v];

        if (!susp[v])
          susp[v] = true, q.push(v);
      }
    }

    vector<int> res;
    for (int u = 0; u < n; ++u) {
      if (susp[u] && invoked[u]) {
        vector<int> resAll(n);
        iota(resAll.begin(), resAll.end(), 0);
        return resAll;
      }

      if (!susp[u])
        res.push_back(u);
    }

    return res;
  }
};
