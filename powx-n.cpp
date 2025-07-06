#include <cstdint>

class Solution {
public:
  double myPow(double x, int n) {
    int64_t nl = n > 0 ? n : -static_cast<int64_t>(n);
    double res = 1;

    while (nl) {
      if (nl & 1) {
        res *= x;
      }

      x *= x;
      nl >>= 1;
    }

    return n > 0 ? res : 1 / res;
  }
};
