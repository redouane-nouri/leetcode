/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  string smallestNumber(string num, long long t) {
    ll tt = t;
    for (int i = 2; i <= 9; ++i)
      while (tt % i == 0)
        tt /= i;

    if (tt > 1)
      return "-1";

    const int SZ = num.size();
    vector<ll> r(SZ + 1);
    int zPos = SZ - 1;
    r[0] = t;

    for (int i = 0; i < SZ; ++i) {
      if (num[i] == '0') {
        zPos = i;
        break;
      }

      r[i + 1] = r[i] / gcd(r[i], num[i] - '0');
    }

    if (r[SZ] == 1)
      return num;

    for (int i = zPos; i >= 0; --i) {
      while (++num[i] <= '9') {
        ll tt = r[i] / gcd(r[i], num[i] - '0');
        int dig = 9;

        for (int j = SZ - 1; j > i; --j) {
          while (tt % dig)
            --dig;

          tt /= dig;
          num[j] = dig + '0';
        }

        if (tt == 1)
          return num;
      }
    }

    string ans;
    ans.reserve(SZ + 1);

    for (int dig = 9; dig >= 2; --dig)
      while (t % dig == 0)
        ans.push_back(dig + '0'), t /= dig;

    ans += string(max(SZ + 1 - (int)ans.size(), 0), '1');
    reverse(ans.begin(), ans.end());

    return ans;
  }
};
