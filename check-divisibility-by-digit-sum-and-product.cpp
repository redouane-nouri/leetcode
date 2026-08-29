/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

class Solution {
public:
  bool checkDivisibility(int n) {
    int x = n, s = 0, p = 1;

    while (n) {
      int d = n % 10;

      s += d, p *= d, n /= 10;
    }

    return x % (s + p) == 0;
  }
};
