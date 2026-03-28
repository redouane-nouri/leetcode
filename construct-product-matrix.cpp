/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 12345;

public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> pre(M, vector<int>(N));

    long long p = 1;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        pre[i][j] = p, p = p * grid[i][j] % MOD;

    long long s = 1;
    for (int i = M - 1; i >= 0; --i)
      for (int j = N - 1; j >= 0; --j)
        pre[i][j] = pre[i][j] * s % MOD, s = s * grid[i][j] % MOD;

    return pre;
  }
};
