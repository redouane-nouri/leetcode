/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  ll countCommas(ll n) {
    ll ans = 0, group = 1000;

    while (group <= n) {
      ans += n - group + 1;
      group *= 1000;
    }

    return ans;
  }
};
