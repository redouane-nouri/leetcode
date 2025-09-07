#include <vector>

class Solution {
public:
  std::vector<int> sumZero(int n) {
    std::vector<int> res(n);

    for (int i = 1; i < n; i += 2) {
      res[i - 1] = i;
      res[i] = -i;
    }

    if (n % 2 == 1)
      res[n - 1] = 0;

    return res;
  }
};
