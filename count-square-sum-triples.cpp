#include <cmath>

class Solution {
public:
  int countTriples(int n) {
    int ans = 0, nn = n * n;

    for (int a = 1; a <= n; ++a) {
      int aa = a * a;

      for (int b = 1; b <= n; ++b) {
        int cc = aa + b * b;

        if (cc > nn)
          break;

        int c = std::sqrt(cc);

        if (c * c == cc)
          ++ans;
      }
    }

    return ans;
  }
};
