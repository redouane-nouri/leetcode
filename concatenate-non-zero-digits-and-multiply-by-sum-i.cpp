/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long sumAndMultiply(int n) {
    long long x = 0, s = 0, p = 1;

    while (n) {
      int d = n % 10;
      if (d)
        x += p * d, s += d, p *= 10;

      n /= 10;
    }

    return x * s;
  }
};
