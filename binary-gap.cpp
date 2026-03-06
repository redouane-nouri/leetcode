#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int binaryGap(int n) {
    int ans = 0, l = 0;
    n >>= __builtin_ctz(n) + 1;

    while (n) {
      ++l;

      if ((n & 1) == 1) {
        ans = max(ans, l);
        l = 0;
      }

      n >>= 1;
    }

    return ans;
  }
};
