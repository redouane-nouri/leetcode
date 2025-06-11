#include <climits>
#include <cstdlib>

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
      return INT_MAX;
    }

    bool isPos = (dividend < 0) ^ (divisor < 0) ? false : true;
    long long dvdnd = std::abs(static_cast<long long>(dividend)),
              dvsr = std::abs(static_cast<long long>(divisor)), tmp, multiple,
              res = 0;

    while (dvdnd >= dvsr) {
      tmp = dvsr;
      multiple = 1;

      while ((tmp << 1) <= dvdnd) {
        tmp <<= 1;
        multiple <<= 1;
      }

      dvdnd -= tmp;
      res += multiple;
    }

    return isPos ? static_cast<int>(res) : static_cast<int>(-res);
  }
};
