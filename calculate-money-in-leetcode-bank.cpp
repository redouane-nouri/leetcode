#include <algorithm>

class Solution {
public:
  int totalMoney(int n) {
    int res = 0, base = 1;

    for (int i = 0; i < (n + 6) / 7; ++i) {
      for (int j = 0; j < std::min(7, n - i * 7); ++j) {
        res += base + j;
      }

      ++base;
    }

    return res;
  }
};
