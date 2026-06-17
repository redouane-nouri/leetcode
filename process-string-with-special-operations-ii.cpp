/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  char processStr(string s, long long k) {
    ll len = 0;

    for (char &c : s) {
      switch (c) {
      case '*':
        len = max(0LL, len - 1);
        break;

      case '#':
        len <<= 1;
        break;

      case '%':
        break;

      default:
        ++len;
        break;
      }
    }

    if (k + 1 > len)
      return '.';

    for (int i = s.size() - 1; i >= 0; --i) {
      switch (s[i]) {
      case '*':
        ++len;
        break;

      case '%':
        k = len - 1 - k;
        break;

      case '#': {
        ll half = len >> 1;

        if (k >= half)
          k -= half;

        len = half;
        break;
      }

      default:
        if (k == --len)
          return s[i];
        break;
      }
    }

    return '.';
  }
};
