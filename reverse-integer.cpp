#include <climits>

class Solution {
public:
  int reverse(int x) {
    int res = 0, dig;

    while (x != 0) {
      dig = x % 10;

      if (x > 0) {
        if (res > (INT_MAX - dig) / 10)
          return 0;
      } else {
        if (res < (INT_MIN - dig) / 10)
          return 0;
      }

      res = res * 10 + dig;
      x /= 10;
    }

    return res;
  }
};
