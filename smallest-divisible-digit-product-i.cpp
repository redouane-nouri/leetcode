/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int smallestNumber(int n, int t) {
    for (int num = n; num <= n + 9; ++num) {
      int x = num, p = 1;

      while (x)
        p *= x % 10, x /= 10;

      if (p % t == 0)
        return num;
    }

    return -1;
  }
};
