/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class LCA {
  vector<vector<int>> graph, ancestor;
  vector<int> depth;
  int ancestorMaxDepth;

  void calcDepth(const int node, const int parent) {
    ancestor[node][0] = parent;

    for (auto &neighbor : graph[node]) {
      if (neighbor == parent)
        continue;

      depth[neighbor] = depth[node] + 1;
      calcDepth(neighbor, node);
    }
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);

    for (int jump = ancestorMaxDepth - 1; jump >= 0; --jump)
      if (depth[u] <= depth[ancestor[v][jump]])
        v = ancestor[v][jump];

    if (u == v)
      return u;

    for (int jump = ancestorMaxDepth - 1; jump >= 0; --jump)
      if (ancestor[u][jump] != ancestor[v][jump])
        u = ancestor[u][jump], v = ancestor[v][jump];

    return ancestor[u][0];
  }

public:
  LCA(const vector<vector<int>> &edges) {
    const int numNodes = edges.size() + 1;
    ancestorMaxDepth = __lg(numNodes) + 1;

    // +1 because 1-indexed
    depth.resize(numNodes + 1);
    graph.resize(numNodes + 1);
    ancestor.resize(numNodes + 1, vector<int>(ancestorMaxDepth, 0));

    for (auto &e : edges)
      graph[e[0]].push_back(e[1]), graph[e[1]].push_back(e[0]);

    calcDepth(1, 1);

    for (int jump = 1; jump < ancestorMaxDepth; ++jump)
      for (int u = 1; u <= numNodes; ++u)
        ancestor[u][jump] = ancestor[ancestor[u][jump - 1]][jump - 1];
  }

  int dist(const int u, const int v) {
    return depth[u] + depth[v] - (depth[lca(u, v)] << 1);
  }
};

class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                vector<vector<int>> &queries) {
    LCA lca(edges);

    const int N = edges.size() + 1;
    vector<int> pow2(N);

    pow2[0] = 1;
    for (int i = 1; i < N; ++i)
      pow2[i] = (pow2[i - 1] << 1) % MOD;

    vector<int> ans;
    ans.reserve(queries.size());

    for (auto &q : queries)
      q[0] == q[1] ? ans.push_back(0)
                   : ans.push_back(pow2[lca.dist(q[0], q[1]) - 1]);

    return ans;
  }
};
