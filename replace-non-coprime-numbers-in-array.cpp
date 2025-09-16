#include <numeric>
#include <vector>

class Solution {
public:
  std::vector<int> replaceNonCoprimes(std::vector<int> &nums) {
    std::vector<int> res;
    int ri = -1;

    for (int &n : nums) {
      res.push_back(n);
      ++ri;

      while (ri > 0) {
        int g = std::gcd(res[ri - 1], res[ri]);

        if (g == 1)
          break;

        res[ri - 1] = static_cast<int>(1LL * res[ri - 1] / g * res[ri]);
        res.pop_back();
        --ri;
      }
    }

    return res;
  }
};
