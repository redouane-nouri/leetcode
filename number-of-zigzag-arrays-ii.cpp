/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Matrix = vector<vector<ll>>;

class Solution {
  static constexpr ll MOD = 1'000'000'007;

  Matrix mul(const Matrix &a, const Matrix &b) {
    const int N = a.size(), M = b[0].size(), O = a[0].size();
    Matrix res(N, vector<ll>(M, 0));

    for (int i = 0; i < N; ++i)
      for (int k = 0; k < O; ++k)
        if (a[i][k] != 0)
          for (int j = 0; j < M; j++)
            res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;

    return res;
  }

  Matrix matExpo(Matrix &b, ll e, Matrix &res) {
    while (e > 0) {
      if (e & 1)
        res = mul(res, b);

      b = mul(b, b);
      e >>= 1;
    }

    return res;
  }

public:
  int zigZagArrays(const int N, const int L, const int R) {
    int range = R - L + 1;
    if (N == 1)
      return range;

    int sz = range << 1;
    Matrix tm(sz, vector<ll>(sz, 0));

    for (int v = 0; v < range; ++v) {
      for (int w = v + 1; w < range; ++w)
        tm[v][range + w] = 1;

      for (int w = 0; w < v; ++w)
        tm[range + v][w] = 1;
    }

    Matrix dp(1, vector<ll>(sz, 1));
    dp = matExpo(tm, N - 1, dp);

    ll ans = 0;
    for (int i = 0; i < sz; ++i)
      ans = (ans + dp[0][i]) % MOD;

    return ans;
  }
};
