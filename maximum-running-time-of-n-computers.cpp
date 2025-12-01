#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
  long long maxRunTime(int n, std::vector<int> &batteries) {
    long long l = 0,
              h = std::accumulate(batteries.begin(), batteries.end(), 0LL) / n;

    auto canRun = [&batteries, &n](long long t) -> bool {
      long long tot = 0;

      for (long long b : batteries)
        tot += std::min(b, t);

      return tot >= t * n;
    };

    while (l < h) {
      long long m = l + (h - l + 1) / 2;

      if (canRun(m))
        l = m;
      else
        h = m - 1;
    }

    return l;
  }
};
