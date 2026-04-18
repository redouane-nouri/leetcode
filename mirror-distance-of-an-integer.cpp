
/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int mirrorDistance(int n) {
    const auto rev = [](int x) -> int {
      int ans = 0;

      while (x) {
        ans = ans * 10 + x % 10;
        x /= 10;
      }
      return ans;
    };

    return abs(n - rev(n));
  }
};
