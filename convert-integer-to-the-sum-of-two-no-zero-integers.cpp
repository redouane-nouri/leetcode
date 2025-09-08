#include <vector>

class Solution {
public:
  std::vector<int> getNoZeroIntegers(int n) {
    auto hasNoZero = [](int x) {
      while (x) {
        if (x % 10 == 0)
          return false;

        x /= 10;
      }

      return true;
    };

    for (int i = 1; i < n; ++i) {
      if (hasNoZero(i) && hasNoZero(n - i))
        return {i, n - i};
    }

    return {};
  }
};
