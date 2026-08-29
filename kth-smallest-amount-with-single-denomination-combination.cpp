/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  long long findKthSmallest(vector<int> &coins, int k) {
    const int SZ = coins.size(), SBS = 1 << SZ;

    vector<ll> lcm(SBS);
    vector<int> popCount(SBS);

    sort(coins.begin(), coins.end());

    ll r = 1LL * coins[0] * k + 1;

    for (int subset = 1; subset < SBS; ++subset) {
      ll curLcm = 1;

      for (int i = 0; i < SZ; ++i) {
        if (subset >> i & 1) {
          popCount[subset]++;

          ll t = curLcm / gcd(curLcm, coins[i]);

          if (t <= r / coins[i]) {
            curLcm = t * coins[i];
          } else {
            curLcm = r + 1;
            break;
          }
        }
      }

      lcm[subset] = curLcm;
    }

    auto count = [&lcm, &popCount, &SBS](ll x) -> ll {
      ll ans = 0;

      for (int subset = 1; subset < SBS; ++subset) {
        if (lcm[subset] > x)
          continue;

        if (popCount[subset] & 1)
          ans += x / lcm[subset];
        else
          ans -= x / lcm[subset];
      }

      return ans;
    };

    ll l = k;

    while (l < r) {
      ll m = l + (r - l) / 2;

      if (count(m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
