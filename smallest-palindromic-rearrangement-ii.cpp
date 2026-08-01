/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
  ll combination(int n, int r) {
    if (r > n || r < 0)
      return 0;

    r = min(r, n - r);
    ll res = 1;

    for (int i = 1; i <= r; ++i) {
      if (res > LLONG_MAX / (n - r + i))
        return LLONG_MAX;

      res = res * (n - r + i) / i;
    }

    return res;
  }

  ll countWays(const int (&cnt)[26], ll k, int rem) {
    ll ways = 1;

    for (int i = 0; i < 26; ++i) {
      if (!cnt[i])
        continue;

      ll c = combination(rem, cnt[i]);
      if (c && ways > k / c)
        return k + 1;

      ways *= c;
      if (ways > k)
        return k + 1;

      rem -= cnt[i];
    }
    return ways;
  }

public:
  string smallestPalindrome(string s, ll k) {
    const int half = s.length() >> 1;
    int cnt[26] = {0};
    for (int i = 0; i < half; ++i)
      cnt[s[i] - 'a'] += 1;

    string l = "";
    ll startIndex = 1;

    for (int pos = 0; pos < half; ++pos) {
      for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 0)
          continue;

        cnt[i] -= 1;
        ll ways = countWays(cnt, k, half - pos - 1);

        if (startIndex + ways > k) {
          l += i + 'a';
          break;
        }

        cnt[i] += 1;
        startIndex += ways;
      }
    }

    if (l.length() < half)
      return "";

    string m = s.length() % 2 != 0 ? string(1, s[half]) : "";
    string r = l;
    reverse(r.begin(), r.end());

    return l + m + r;
  }
};
