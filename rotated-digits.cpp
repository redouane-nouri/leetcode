/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isGood(int x) {
    bool changed = false;

    while (x) {
      switch (x % 10) {
      case 3:
      case 4:
      case 7:
        return false;

      case 2:
      case 5:
      case 6:
      case 9:
        changed = true;
      }

      x /= 10;
    }

    return changed;
  }

  int rotatedDigits(int n) {
    int ans = 0;

    for (int i = 1; i <= n; ++i)
      if (isGood(i))
        ++ans;

    return ans;
  }
};
