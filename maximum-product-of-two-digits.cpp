/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxProduct(int n) {
    int d1 = 0, d2 = 0;

    while (n) {
      int d = n % 10;

      d2 = max(d2, min(d1, d));
      d1 = max(d1, d);

      n /= 10;
    }

    return d1 * d2;
  }
};
