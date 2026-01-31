#include <bits/stdc++.h>
using namespace std;
struct Trie {
  Trie *child[26];
  int id;
  Trie() {
    for (int i = 0; i < 26; ++i)
      child[i] = nullptr;
    id = -1;
  }
};
class Solution {
public:
  long long minimumCost(string source, string target, vector<string> &original,
                        vector<string> &changed, vector<int> &cost) {
    const int N = source.size(), M = original.size(), INF = INT_MAX >> 1;
    vector<vector<int>> dist(M << 1, vector<int>(M << 1, INF));
    Trie *root = new Trie();
    for (int i = 0; i < M << 1; ++i)
      dist[i][i] = 0;
    int id = 0;
    const auto insert = [&root, &id](const string &s) -> int {
      Trie *node = root;
      for (const char &c : s) {
        int i = c - 'a';
        if (node->child[i] == nullptr)
          node->child[i] = new Trie();
        node = node->child[i];
      }
      if (node->id == -1)
        node->id = id++;
      return node->id;
    };
    for (int i = 0; i < M; ++i) {
      int u = insert(original[i]), v = insert(changed[i]);
      dist[u][v] = min(dist[u][v], cost[i]);
    }
    for (int k = 0; k < id; ++k)
      for (int i = 0; i < id; ++i)
        for (int j = 0; j < id; ++j)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    vector<long long> dp(N + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
      if (dp[i - 1] != LLONG_MAX) {
        if (source[i - 1] == target[i - 1])
          dp[i] = min(dp[i], dp[i - 1]);
        Trie *u = root, *v = root;
        for (int j = i - 1; j < N; ++j) {
          u = u->child[source[j] - 'a'], v = v->child[target[j] - 'a'];
          if (!u || !v)
            break;
          if (u->id != -1 && v->id != -1 && dist[u->id][v->id] != INF)
            dp[j + 1] = min(dp[j + 1], dp[i - 1] + dist[u->id][v->id]);
        }
      }
    }
    return dp[N] == LLONG_MAX ? -1LL : dp[N];
  }
};
