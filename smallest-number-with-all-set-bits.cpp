#include <bit>

class Solution {
public:
  int smallestNumber(int n) {
    if ((n & (n + 1)) == 0) {
      return n;
    }

    return (1 << (32 - __builtin_clz(n))) - 1;
  }
};
