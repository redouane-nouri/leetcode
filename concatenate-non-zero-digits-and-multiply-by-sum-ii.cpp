/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll eucMod(const ll &a, const ll &mod) {
  return (a % mod + abs(mod)) % abs(mod);
};

const int MOD = 1e9 + 7, MAX = 1e5 + 1;
ll pow10[MAX];

bool init = []() -> bool {
  pow10[0] = 1;
  for (int i = 1; i < MAX; ++i)
    pow10[i] = pow10[i - 1] * 10 % MOD;

  return true;
}();

class Solution {
public:
  vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    const int N = s.size();
    vector<int> sum(N + 1, 0), cnt(N + 1, 0);
    vector<ll> x(N + 1, 0);

    for (int i = 0; i < N; ++i) {
      int d = s[i] - '0';
      cnt[i + 1] = cnt[i] + (d > 0);
      sum[i + 1] = sum[i] + d;
      x[i + 1] = d > 0 ? ((x[i] * 10 + d) % MOD) : (x[i]);
    }

    vector<int> res;
    res.reserve(queries.size());

    for (auto &q : queries) {
      const int &l = q[0], r = q[1] + 1, cntVal = cnt[r] - cnt[l],
                sumVal = sum[r] - sum[l];
      ll xVal = eucMod(x[r] - x[l] * pow10[cntVal], MOD);
      res.push_back(xVal * sumVal % MOD);
    }

    return res;
  }
};
