#include <unordered_map>
#include <vector>

class Solution {
  const int MOD = 1'000'000'007;

  long long nCK(int n, int k) {
    if (k > n)
      return 0;

    if (k > n - k)
      k = n - k;

    long long c = 1;
    for (int i = 1; i <= k; ++i)
      c = c * (n - i + 1) / i;

    return c;
  }

public:
  int countTrapezoids(std::vector<std::vector<int>> &points) {
    std::unordered_map<int, int> yFreqMap;

    for (const auto &p : points)
      ++yFreqMap[p[1]];

    long long ans = 0, upperSides = 0;

    for (const auto &[k, v] : yFreqMap) {
      long long lowerSides = nCK(v, 2);
      ans += upperSides * lowerSides;
      upperSides += lowerSides;
    }

    return ans % MOD;
  }
};
