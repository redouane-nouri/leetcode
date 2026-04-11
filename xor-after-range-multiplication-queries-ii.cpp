/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class Solution {
  static constexpr int MOD = 1e9 + 7;

  ll expo(ll b, ll e, ll m) {
    ll r = 1;

    while (e) {
      if (e & 1)
        r = r * b % m;

      b = b * b % m;
      e >>= 1;
    }

    return r;
  }

  ll inv(ll v, ll m) { return expo(v, m - 2, m); }

public:
  int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
    const int N = nums.size(), K = sqrt(N);
    vector<vector<vector<int>>> grps(K);

    for (auto &q : queries)
      if (q[2] < K)
        grps[q[2]].push_back({q[0], q[1], q[3]});
      else
        for (int i = q[0]; i <= q[1]; i += q[2])
          nums[i] = 1ll * nums[i] * q[3] % MOD;

    for (int k = 1; k < K; ++k) {
      if (!grps[k].empty()) {
        vector<ll> muls(N + K - 1, 1);

        for (auto &q : grps[k]) {
          muls[q[0]] = muls[q[0]] * q[2] % MOD;
          int reset = q[0] + ((q[1] - q[0]) / k + 1) * k;
          muls[reset] = muls[reset] * inv(q[2], MOD) % MOD;
        }

        for (int i = k; i < N; ++i)
          muls[i] = muls[i] * muls[i - k] % MOD;

        for (int i = 0; i < N; ++i)
          nums[i] = nums[i] * muls[i] % MOD;
      }
    }

    int ans = 0;

    for (int i = 0; i < N; ++i)
      ans ^= nums[i];

    return ans;
  }
};
